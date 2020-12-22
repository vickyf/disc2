function [ DiscOutput ] = disc_main(stim_name, DiscParams, ImportParams, Prefs)
% DISC_MAIN - main function for running the disc model
%
% Synopsis
%   [ DiscOutput ] = disc_main(stim_name, DiscParams, ImportParams, Prefs)
%
% Description
%   Main function to run the disc model. Will convert a raw image into an
%   edge map to be processed by the model if not yet existing. It will then
%   run the model based on the parameter settings given by the user. While
%   returning all of the findings in DiscOutput it will also save all the
%   computed information in the output folder.
%
%   Note when running a lot of images, the output folder could become
%   rather large so be aware of your disk space!
%
% Inputs ([]s are optional)
%   (str)    stim_name
%   (struct) DiscParams
%   (struct) ImportParams
%   (struct) Prefs
%
% Outputs ([]s are optional)
%   (struct) DiscOutput
%
% Examples
%   <Example Code>
%
% See also
%   disc_main, disc_params_default, ...
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

%% preliminaries and stimulus importer

% get filename
[~,name,~] = fileparts(stim_name);

% append Aug when augmented model is being used
if DiscParams.weightLCL>0
    name = strcat(name,'Aug');
end

% has the file been processed before?
if exist(strcat(Prefs.output,'/import_',name,'.mat'),'file')
    fprintf("Image %s already imported before ...\n", stim_name)
    disp("Loading existing <ImportParams> and <DiscOutput> ...")
    load(strcat(Prefs.output,'/import_',name));
else
    % import the figure with name stim_name
    fprintf("Importing Image %s ...\n",stim_name);
    [pts_pos, pts_color] = import_stimulus(strcat(Prefs.data,'/',stim_name), ImportParams);

    % initialize the output datastructure
    disp("Initializing BOWN signal matrices for computation ...")
    DiscOutput = disc_init(stim_name, pts_pos, pts_color, DiscParams);
    
    % Find neighbouring points for augmented model
    DiscOutput.NB = disc_neighboring_points(DiscOutput,DiscParams.Knear);
    
    % save this part so that it can be loaded easily later on
    disp("Saving initialized values to file ...")
    save(strcat(Prefs.output,'/import_',name),'ImportParams','Prefs', ...
        'DiscOutput','-v7.3');
end

%% run the disc model

% set maximum iterations
DiscParams.max_iter = DiscOutput.num_nodes*2;

% compute BOWN using DISC model
disp("Starting DISC2 BOWN computation ...")
if exist("disc_compute_bown_mex", "file")
    DiscOutput = disc_compute_bown_mex(DiscOutput,DiscParams);
else
    DiscOutput = disc_compute_bown(DiscOutput,DiscParams);
end

% save model output
disp("Finalizing DISC2 BOWN computation and Saving output")
save(strcat(Prefs.output,'/disc_',name),'ImportParams','Prefs','DiscOutput','DiscParams','-v7.3');

end