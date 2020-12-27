function [DiscParams] = disc_params_default()
% DISC_PARAMS_DEFAULT - sets up default parameters for running disc model
%
% Synopsis
%   [DiscParams] = disc_params_default()
%
% Description
%   Sets up default parameters for running disc model. To run the model
%   presented in the paper leave these parameters as they are.
%
% Inputs ([]s are optional)
%   ---
%
% Outputs ([]s are optional)
%   (struct) DiscParams Parameter settings for running disc model. It is a
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

% initial bown
DiscParams.initial_bown  = 0.5;

% space constant
DiscParams.space_constant = 200;

% which feature do we include? -- all the combinations we want
% (1) convexity; (2) color ownerside; (3) color non-ownerside; (4) color contrast
DiscParams.agreement_combo = [1,2,3];

% parameter set for the bown computation to incorporate convexity bias. If
% 1 this configuration is seen as in agreement, if 0 not.
% i and j here is are BOWN signals
% (1) i and j are collinear, and the norm of j is facing in the same
% direction as the norm of i
% (2) i and j are collinear, and the norm of j is facing away from the norm
% of i.
% (3) j is located in the direction of the norm of i, and the norm of j is 
% facing the norm of i.
% (4) j is located in the direction of the norm of i, and the norm of j is
% facing away from i.
% (5) j is located in the opposite direction of the norm of i, and the norm
% of j is facing i.
% (6) j is located in the opposite direction of the norm of i, and the norm
% of j is facing away from i.
% (7) all left-overs fall in this category
DiscParams.bown_params = [1,0,1,0,0,0,0];

% set convergence criterion
DiscParams.convergence_lambda = 1e-05;

% maximal iterations -- these are programatically also set by disc_main
DiscParams.max_iter = 1000;

%finding neighbor K value (3: 1 point on both side, 5: 2 points...)
% XXX more explanation needed
numPair = 400;
DiscParams.Knear = numPair*2 + 1;

%weight for LCL and GBL for bown
DiscParams.weightLCL = 0; % local weight if 0 then is orignal model, 1.0 then its augmented
DiscParams.weightGBL = 1; % global weight

% co-linear criteria for local BOWN
DiscParams.linearAngTh = 20; %in degree maximum difference of direction to be considered as co-linear
DiscParams.distLCL = 100; %maximam distance for local (LCL) colinearity

end

