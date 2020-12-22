function [ DiscOutput ] = disc_init(stim_name,pts_pos,pts_color,DiscParams)
% DISC_INIT - initiailized the DiscOutput structure
%
% Synopsis
%   [DiscOutput] = disc_init()
%
% Description
%   Initializes output structure with point locations and color values at
%   each of the edges with, initializing both bown signals at each
%   location. As you will see below this ends up in some specific matrices
%   that will ease computation when executing the bown computation code
%   later in the process.
%
% Inputs ([]s are optional)
%   (str)    stim_name  Name of the stimulus that will be imported
%   (matrix) pts_pos    3xN matrix of boundary node positions [x,y,angle]
%   (matrix) pts_color  3xN matrix of color on either side of the boundary 
%                       node [color_left,color_right,dection threshold from
%                       import function]
%   (str)   DiscParams  Params struct used for default BOWN signal value
%
% Outputs ([]s are optional)
%   (struct) DiscOutput Structure containing all the info that will be
%                       produced by the disc_main function
%
% Examples
%   <Example Code>
%
% See also
%   disc_main, disc_params_default, disc_compute_bown,
%   disc_compute_agreement
%
% Requirements
%   ---

% References
%   ...
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
        
DiscOutput.stim_name = stim_name;
DiscOutput.num_nodes = 2*size(pts_pos,2);
DiscOutput.pos_x = [pts_pos(1,:),pts_pos(1,:)]; % x position
DiscOutput.pos_y = [pts_pos(2,:),pts_pos(2,:)];% y position
DiscOutput.dx = [pts_pos(4,:),-pts_pos(4,:)];
DiscOutput.dy = [pts_pos(5,:),-pts_pos(5,:)];
DiscOutput.angle = [pts_pos(3,:),pts_pos(3,:)+pi];% bown node direction
DiscOutput.bown = DiscParams.initial_bown.*ones(1,DiscOutput.num_nodes); % initial bown signal
DiscOutput.color_norm = [pts_color(1,:),pts_color(2,:)];
DiscOutput.color_contrast = [pts_color(1,:)-pts_color(2,:),pts_color(2,:)-pts_color(1,:)];
DiscOutput.bown_timecourse = DiscParams.initial_bown.*ones(2*DiscOutput.num_nodes+1,DiscOutput.num_nodes); % to save the bown timecourse
DiscOutput.num_iter = 0; % number of iterations needed by the model

% to save the graded pairwise distances
DiscOutput.dist_decay = ones(DiscOutput.num_nodes,DiscOutput.num_nodes);
DiscOutput.distance   = ones(DiscOutput.num_nodes,DiscOutput.num_nodes);
DiscOutput.agreement = zeros(DiscOutput.num_nodes,DiscOutput.num_nodes,6);

% for later plotting purposes get the axes
DiscOutput.axes_range = [min(DiscOutput.pos_x)-10, max(DiscOutput.pos_x)+10, ...
    min(DiscOutput.pos_y)-10, max(DiscOutput.pos_y)+10];

end

