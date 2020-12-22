function Inew = import_color_clustering(im,varargin)
% IMPORT_SEG_GRAYCLUSTER segmentation based on grayscale clustering
%
% Synopsis
%   [ Inew ] = import_color_clustering(im,varargin)
%
% Description
%   Reformatted version of Honza's code <ColorClusteringThNew2>
%
% Inputs ([]s are optional)
%   ()
%
% Outputs ([]s are optional)
%   ()
%
% Examples
%   <Example Code>
%
% See also
%   disc_main, import_seg_graycluster
%
% Requirements
%   ---

% References
%   ...
%
% Authors
%   Honza Knopp <knopp1j@gmail.com>*
%   Vicky Froyen <vicky.froyen@gmail.com>
%   Naoki Kogo <naoki.kogo@gmail.com>
%
% License
%   DISC2 is free software accompanying our paper:
%   "Emergence of border-ownership by large-scale consistency and 
%   long-range interactions: Neuro-computational model to reflect
%   global configurations"
%   Copyright (C) 2020 Vicky Froyen, Naoki Kogo
%
%   This program is free software; you can redistribute it and/or modify
%   it under the terms of the GNU General Public License as published by
%   the Free Software Foundation; either version 2 of the License, or
%   (at your option) any later version.
%
%   This program is distributed in the hope that it will be useful,
%   but WITHOUT ANY WARRANTY; without even the implied warranty of
%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%   GNU General Public License for more details.
%
%   You should have received a copy of the GNU General Public License along
%   with this program; if not, write to the Free Software Foundation, Inc.,
%   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
%
% Changes
%   see <git log>

p = inputParser;
p.addOptional('N', 10); %%% number of initial clusters
p.addOptional('cth', 0.0125); %%%  treshold for nu,ber of clusters decision
p.addOptional('ngh_', []); %%% vicintny when introducing spatial relation
p.addOptional('remove_red', 0); %%% remove red color
p.parse(varargin{:}); fldnames = fieldnames(p.Results); for a=1:length(fldnames), eval([fldnames{a},' = p.Results.',fldnames{a},';']); end

%% remove red color
if remove_red
    red = [255 0 0];
    imR = im(:,:,1);
    imG = im(:,:,2);
    imB = im(:,:,3);
    %--- find neigh. to each pixel using conv2
    nghR = conv2(double(imR),double([1 0 0]),'same');
    nghG = conv2(double(imG),double([1 0 0]),'same');
    nghB = conv2(double(imB),double([1 0 0]),'same');
    %--- find red color pixels
    red_in_im = imR==red(1) & imG==red(2) & imB==red(3); %%% find red in image
    if sum(red_in_im(:))>0 %%% if im has red color
        %--- fidn the color of neigh region
        nR = nghR(red_in_im==1);
        nG = nghG(red_in_im==1);
        nB = nghB(red_in_im==1);
        %--- now, replace red color
        imR(red_in_im) = nR(end);
        imG(red_in_im) = nG(end);
        imB(red_in_im) = nB(end);
        im(:,:,1) = imR;
        im(:,:,2) = imG;
        im(:,:,3) = imB;
    end
end

%% convert to gray
if ndims(im)==3
    im = rgb2gray(im);
end

%% gray chanel clustering
treshold = size(im,1)*size(im,2)*cth;%0.005;%*0.0125;  %%% at least 1.25% pixels has to have the color
[hn,hx] = hist(double(im(:)),N); %%% hist of colors
if 0 %%% visulize hist
    hist(double(im(:)),N*20); xlabel('color value');ylabel('# of occurences'); hold on;
    plot([0 255],[treshold treshold],'-g');legend('hist','tresh');
end
clusters = hx(hn>treshold); %%% gray colors of clusters
i=knnsearch(clusters' , double(im(:)));  %%% assign im's color to clusters
Inew = reshape( clusters(i) , size(im,1),size(im,2) );   %uint8(reshape( clusters(i) , size(im,1),size(im,2) ));   %%% for each pixel, save clusters color instead
Inew = uint8(Inew);

%% ngh constrins
if ~isempty(ngh_) && ngh_>0
    for a=ngh_+1:size(Inew,1)-ngh_-1
        for b=ngh_+1:size(Inew,2)-ngh_-1
            Ingh = Inew(a-ngh_:a+ngh_,b-ngh_:b+ngh_);
            Inew(a,b) = mode(Ingh(:));  %%% get most occuring number :-)
        end
    end
end
