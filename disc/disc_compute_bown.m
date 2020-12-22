function [ DiscOutput ] = disc_compute_bown(DiscOutput,DiscParams)
% DISC_COMPUTE_BOWN - core of the DISC model
%
% Synopsis
%   [ DiscOutput ] = disc_compute_bown(DiscOutput,DiscParams)
%
% Description
%   First this code will compute correspondencies between different BOWN
%   nodes to decide if they will interact with eachother or not. Then based
%   on this correspondence/agreement matrix it will start propagating BOWN
%   signals throughout the image until convergence is reached.
%
% Inputs ([]s are optional)
%   (struct) DiscOutput
%   (struct) DiscParams
%
% Outputs ([]s are optional)
%   (struct) DiscOutput
%
% Examples
%   <Example Code>
%
% See also
%   disc_main
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

%\codegen
coder.inline('never')

%% compute if bown nodes are in agreement

disp(">> STEP 1: Computing Agreement/Correspondence matrix between BOWN signals ...")
DiscOutput = disc_compute_agreement(DiscOutput,DiscParams);

%%%local
%agreement: less than distLCL, distance decay, owner side color consistency, colinearity
agreement_LCL = (DiscOutput.distance<=DiscParams.distLCL).* ...
                DiscOutput.dist_decay.*DiscOutput.agreement(:,:,2).* ...
                DiscOutput.agreement(:,:,5);
            
%%%global
% combine different agreement features as set by the user in
% DiscParams.agreement_combo with the distance decay matrix.
agreement_GBL = DiscOutput.dist_decay.*...
    prod(DiscOutput.agreement(:,:,DiscParams.agreement_combo),3);

% set the initial bown (also the current bown)
current_bown = DiscOutput.bown;
disp(">> DONE")

%% propagate the bown signals based on the agreement matrix

% save the current bown as the initial one in the timecourse matrix
DiscOutput.bown_timecourse(1,:) = current_bown;

% initialize and declare nrep
nrep = 1;

disp(">> STEP 2: Propagating BOWN signals ...")
% iterate till convergence
for nrep = 1:DiscParams.max_iter
    
    % compute the transition vector
    %global
    transition_vectorGBL = current_bown*agreement_GBL;
    %local
    transition_vectorLCL = current_bown*agreement_LCL;

    % update bown
    current_bown = current_bown+ ...
        DiscParams.weightGBL*transition_vectorGBL/(DiscOutput.num_nodes-1)+ ...
        DiscParams.weightLCL*transition_vectorLCL/(DiscParams.Knear-1);

    % no negative "activities" -- they become 0
    current_bown(current_bown<0) = 0;
    
    % normalize bown
    alpha = current_bown(1:DiscOutput.num_nodes/2)+...
        current_bown(DiscOutput.num_nodes/2+1:DiscOutput.num_nodes);
    current_bown = current_bown./repmat(alpha,1,2);
    
    % save the timecourse
    DiscOutput.bown_timecourse(nrep+1,:) = current_bown;
    
    % check for convergence
    if sum(abs(current_bown-DiscOutput.bown_timecourse(nrep,:)))< ...
            DiscOutput.num_nodes*DiscParams.convergence_lambda
        break;
    end
    
end
disp(">> CONVERGED AND DONE")

%% save findings

% save the number of iterations needed
DiscOutput.num_iter = nrep;

% save the converged bown values
DiscOutput.bown = current_bown;

end

