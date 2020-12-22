function neighborDbl = disc_neighboring_points(DiscOutput,k)
% DISC_NEIGHBORING_POINTS
%
% Synopsis
%   [neighborDbl] = disc_neighboring_points(DiscOutput,k)
%
% Description
%   limit the computation to a small area of neighborpoints.
%   neighboring co-curvilinear with same owner direction interact with 
%   eachother this is used for the augmented model
% 
% Inputs ([]s are optional)
%   (struct) DiscOutput
%   (int)    k
%
% Outputs ([]s are optional)
%   (struct) neighborDbl
%
% Examples
%   <Example Code>
%
% See also
%   disc_main, ...
%
% Requirements
%   --
%
% Authors
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

pts = [DiscOutput.pos_x;DiscOutput.pos_y];
idNB = knnsearch(pts', pts', 'k', k, 'Distance', 'euclidean');

%neighbors
neighborDbl = struct(); 
dataRows = [DiscOutput.pos_x;DiscOutput.pos_y;DiscOutput.angle;DiscOutput.dx;DiscOutput.dy;DiscOutput.color_norm]';
for iK=1:k    
    idNBtemp = idNB(:,iK);
    dataRowsDblsort = dataRows(idNBtemp,:);
    neighborDbl(iK).NBind        = idNBtemp;
    neighborDbl(iK).NBpos_x      = dataRowsDblsort(:,1);
    neighborDbl(iK).NBpos_y      = dataRowsDblsort(:,2);
    neighborDbl(iK).NBang        = dataRowsDblsort(:,3);
    neighborDbl(iK).NBdx         = dataRowsDblsort(:,4);
    neighborDbl(iK).NBdy         = dataRowsDblsort(:,5);
    neighborDbl(iK).NBcolor_norm = dataRowsDblsort(:,6);
end

end












