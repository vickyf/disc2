function [ pts_pos, pts_color ] = import_stimulus(stim_name, ImportParams)
% IMPORT_SEG_GRAYCLUSTER segmentation based on grayscale clustering
%
% Synopsis
%   [ pts_pos, pts_color ] = import_seg_graycluster(stim_name, ImportParams)
%
% Description
%   This code redirects and formats the input into what is needed for
%   Honza's naoki_seg_grayCluster_testNew2 code, now renamed as
%   import_seg_graycluster.
%
%   Soon we will merge import_stimulus with import_seg_graycluster. This is
%   merely a function to setup the variables in the right way so that we
%   can run Honza's code without having to change it.
%
% Inputs ([]s are optional)
%   (string)    stim_name   path to the stimulus to be loaded
%   (struct)    ImportParams    
%
% Outputs ([]s are optional)
%   ()
%
% Examples
%   <Example Code>
%
% See also
%   import_seg_graycluster, import_color_clustering
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

%% run Honza's segmentation code
[~,pts,~,pts_color] = import_seg_graycluster(stim_name,'ubcCanny', ...
                      'cth', ImportParams.cth, ...
                      'ngh_',ImportParams.ngh_, ...
                      'colorNumMax', ImportParams.colorNumMax);

% Honza switched x and y so we set them correctly now for easier use
pts_pos = pts;
pts_pos(1,:) = pts(2,:);
pts_pos(2,:) = pts(1,:);

end

