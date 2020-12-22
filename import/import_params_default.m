function [ImportParams] = import_params_default()
% IMPORT_PARAMS_DEFAULT - sets up default parameters for import
%
% Synopsis
%   [DiscParams] = import_params_default()
%
% Description
%   sets up default parameters for the image import functionality. All
%   values below are the default values used in the paper.
%
% Inputs ([]s are optional)
%   ---
%
% Outputs ([]s are optional)
%   (struct) DiscParams Parameter settings for importing figures. It is a
%                       struct containing a set of values.
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

%color clustering param
ImportParams.colorNumMax = 20; % max number of color surfaces in image
ImportParams.cth = 0.001; % threshold for considering something a surface
ImportParams.ngh_ = 2; % vicinity when introducing spatial relation

end

