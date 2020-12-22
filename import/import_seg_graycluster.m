function [E,pts,S,col_ab,Inew] = import_seg_graycluster(image_path,method,varargin)
% IMPORT_SEG_GRAYCLUSTER segmentation based on grayscale clustering
%
% Synopsis
%   [ pts_pos, pts_color ] = import_seg_graycluster(stim_name, ImportParams)
%
% Description
%   Reformatted version of Honza's code <naoki_seg_grayCluster_testNew2>
%
% Inputs ([]s are optional)
%   (string)    input_image 1) image, 2) path to image, or 3) nothing, then 
%                           tst image is processed
%   (string)    method      'sp' superpixel detection
%                           'gm' from matlab
%                           'fo'
%                           'ubcHil'   some method from net
%                           'ubcCanny' canny
%
% Outputs ([]s are optional)
%   ()
%
% Examples
%   <Example Code>
%
% See also
%   disc_main, ...
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

%% set parameters

E=[];pts=[];S=[];col_ab=[];Inew=[];

p = inputParser;
p.addOptional('resize_par', 1); %%% resize ratio
p.addOptional('ori_grad_scale', 3); %%% compute orient?
p.addOptional('ES', []); %%% if computing oriantation for given E, this has E, then I is image used to compute oriantation 
p.addOptional('morph_skel', 1); %%% run skelton morph. operation on the result, this makes lines thin 1pixel, helps for some methods. 
p.addOptional('colorNumMax', 200); %%% tresholeding... max colors??
p.addOptional('cth', .005); %%%  treshold
p.addOptional('ngh_',0); %%% do neighbors
p.addOptional('vis',0); %%% show intermediate eresults
p.addOptional('vis_res',0);  %%% show final result
p.addOptional('save_res_im',1);  %%% 
p.addOptional('orientation',1);  %%% 
p.addOptional('remove_red',0);  %%% remove everything that has red color
p.parse(varargin{:}); fldnames = fieldnames(p.Results); for a=1:length(fldnames), eval([fldnames{a},' = p.Results.',fldnames{a},';']); end;
    

%% read image

% imread the image based on the path
I = imread(image_path);

% color clustering to clean the image
Inew = import_color_clustering(I,'N',colorNumMax,'cth',cth,'ngh_',ngh_,'remove_red',remove_red);

% resize
I_orig = I;
sz_orig = size(Inew);
[Inew] = imresize(Inew,sz_orig(1:2)*resize_par,'nearest');


%% run 'ubcCanny'
% code from http://www.cs.ubc.ca/~woodham/cpsc505/examples/edge-code.html
if length(size(Inew))==3
    A = rgb2gray(Inew);
else
    A = Inew;
end
% Canny edge detection
par = 0.5;
[C1, Ct1] = edge(A,'canny',[],par);
% Recompute lowering both automatically computed thresholds by fraction k
k = 0.75;
E = edge(A,'canny',k*Ct1,par);

%--- also compute segments
ImS = Inew;
ImS = rgb2gray(I_orig);
hy = fspecial('sobel'); hx = hy';
Iy = imfilter(double(ImS), hy, 'replicate');Ix = imfilter(double(ImS), hx, 'replicate');
S = label2rgb(watershed(sqrt(Ix.^2 + Iy.^2)));

%% use morph to make edges thin
if morph_skel
    if vis
        figure(107);
        title('skeleton');
        subplot(1,2,1),imagesc(E);
        subplot(1,2,2),imagesc(bwmorph(E,'skel','Inf'));
    end
    E = bwmorph(E,'skel','Inf');
end

%% find points 
[i,j] = find(E>0);
pts = [i';j'];

%% orient bad points above below normal
if orientation
    if length(size(Inew))==3
        Id = double(rgb2gray(Inew));
    else
        Id = double(Inew);
    end
    if (~exist('ori_grad_scale','var')) || isempty(ori_grad_scale)
        [dx,dy] = gradient(Id);
    else
        mask_dx = [ones(ori_grad_scale) , -ones(ori_grad_scale)];
        mask_dy = [ones(ori_grad_scale) ; -ones(ori_grad_scale)];
        dx = conv2(Id,mask_dx,'same');
        dy = conv2(Id,mask_dy,'same');
    end
    orient1 = atan(dx./dy);
    orient2 = atan(dy./dx);
    for a=1:size(pts,2)
        i = pts(1,a);
        j = pts(2,a);
        % save the dx, dy and make sure the angles are normalized!
        norm_dxdy = norm([dx(i,j),dy(i,j)]);
        dx(i,j) = dx(i,j)/norm_dxdy;
        dy(i,j) = dy(i,j)/norm_dxdy;
        % Honza's code these were not normalized, we fixed that
        pts(3,a) = atan2(dx(i,j),dy(i,j));
        pts(4,a) = dx(i,j);
        pts(5,a) = dy(i,j);
    end
    %--- show orient as vectors

    if vis
        scale_or = 20;
        o1 = cos(pts(3,:))*scale_or + pts(1,:); %%% compute ox oy -vectors Inew will show and move them to pts
        o2 = sin(pts(3,:))*scale_or + pts(2,:);
        figure(108);
        imshow(Inew); hold on;
        plot(pts(2,:),pts(1,:),'.k');
        for a=1:40:size(pts,2) %%% plot arrows for each n-th point
            arrow([pts(2,a) pts(1,a)],[o2(a) o1(a)],'LineWidth',4,'Length',12);
            arrow([pts(2,a) pts(1,a)],[o2(a) o1(a)],'LineWidth',1,'FaceColor','w','Length',12);
        end
    end
    %--- show orient as colormap
    if vis
        O = Id*NaN;
        for a=1:size(pts,2)
            O(pts(1,a),pts(2,a))=pts(3,a);
        end
        figure(109);
        subplot(2,3,1), imagesc(dx); title('dx'); axis off equal;
        subplot(2,3,4), imagesc(dy); title('dy'); axis off equal;
        subplot(2,3,[2 3 5 6]), honza_scatter(bsxfun(@times,pts(2:-1:1,:),[1;-1]),pts(3,:)*0+20,pts(3,:),'filled'); colorbar; title('orientation of points'); axis off equal;
        set(gcf, 'Color', [1 1 1]);
    end
end

%--- get values above and bellow point's normal ---------------------------
if orientation
    scale_ngh = 4;%2; %% get value two pixels above/bellow
    oxA = round(cos(pts(3,:))*scale_ngh+pts(1,:)); %%% ABOVE: compute ox oy -vectors I will show
    oyA = round(sin(pts(3,:))*scale_ngh+pts(2,:));
    oxB = round(-cos(pts(3,:))*scale_ngh+pts(1,:)); %%% BELOOW: compute ox oy -vectors I will show
    oyB = round(-sin(pts(3,:))*scale_ngh+pts(2,:));
    oxA = naoki_out_pts(oxA,size(Inew,1)); %%% now check if Im not out of the border
    oyA = naoki_out_pts(oyA,size(Inew,2));
    oxB = naoki_out_pts(oxB,size(Inew,1));
    oyB = naoki_out_pts(oyB,size(Inew,2));
    for a=1:size(pts,2)
        col_ab(:,a) = [A(oxA(a),oyA(a)) ; A(oxB(a),oyB(a))];
    end
    col_ab(3,:) = col_ab(1,:)-col_ab(2,:);
    if vis
        figure(110)
        subplot(2,2,1), honza_scatter(bsxfun(@times,pts(2:-1:1,:),[1;-1]),pts(3,:)*0+20,col_ab(1,:),'filled'); colorbar; title('above'); axis off equal;
        subplot(2,2,2), honza_scatter(bsxfun(@times,pts(2:-1:1,:),[1;-1]),pts(3,:)*0+20,col_ab(2,:),'filled'); colorbar; title('bellow'); axis off equal;
        subplot(2,2,3), imagesc(Inew); axis off equal;
        subplot(2,2,4), honza_scatter(bsxfun(@times,pts(2:-1:1,:),[1;-1]),pts(3,:)*0+20,col_ab(3,:),'filled'); colorbar; title('diff'); axis off equal;
        set(gcf, 'Color', [1 1 1]);
    end
end

%% plot results
fprintf(' %i points were found\n',size(pts,2));
if vis_res
    figure(111);
    subplot(3,2,1);imshow(Inew,'InitialMagnification',100); hold on;
    title([method,': input image']);
    subplot(3,2,2);imagesc(E); hold on; axis off equal; colormap('hot');
    title([method,': show points']);
    subplot(3,2,[3 4 5 6]); plot(pts(2,:),-pts(1,:),'.r'); axis off equal;
    title([method,': edges as points']);
    set(gcf, 'Color', [1 1 1]);
    if ~isempty(S)
        figure(112);
        imagesc(S);
        axis off equal; title([method,': segmentation']); set(gcf, 'Color', [1 1 1]);
    end
end

%% if resize, put it into the original
pts(1:2,:) = pts(1:2,:)./resize_par;
if vis
    figure(113);
    subplot(2,2,1);imagesc(Inew); title('downsampled');
    subplot(2,2,3); plot(pts(2,:)*resize_par,-pts(1,:)*resize_par,'xk');
    subplot(2,2,2); imagesc(I_orig); hold on; title('original');
    subplot(2,2,4); plot(pts(2,:),-pts(1,:),'xk');
    set(gcf, 'Color', [1 1 1]);
end

end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% take care about points out of the image
function out = naoki_out_pts(in,maxsize)
in(in<1)=1;
in(in>maxsize)=maxsize;
out = in;
end
