%SETUP - sets up the code (compiling and creating user files)
%
% Synopsis
%   setup
%
% Description
%
% See also
%   setup
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

main_folder = pwd;

%% mexing
% compile disc_compute_bown to speed up computation
disp('>>> Compiling model code')
%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config('lib','ecoder',true);
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'disc_compute_bown'.
ARGS = cell(1,1);
ARGS{1} = cell(2,1);
ARGS_1_1 = struct;
ARGS_1_1.stim_name = coder.newtype('string');
ARGS_1_1.stim_name.Properties.Value = coder.typeof('X',[1 13]);
ARGS_1_1.num_nodes = coder.typeof(0);
ARGS_1_1.pos_x = coder.typeof(0,[1 1192]);
ARGS_1_1.pos_y = coder.typeof(0,[1 1192]);
ARGS_1_1.dx = coder.typeof(0,[1 1192]);
ARGS_1_1.dy = coder.typeof(0,[1 1192]);
ARGS_1_1.angle = coder.typeof(0,[1 1192]);
ARGS_1_1.bown = coder.typeof(0,[1 1192]);
ARGS_1_1.color_norm = coder.typeof(0,[1 1192]);
ARGS_1_1.color_contrast = coder.typeof(0,[1 1192]);
ARGS_1_1.bown_timecourse = coder.typeof(0,[2385 1192]);
ARGS_1_1.num_iter = coder.typeof(0);
ARGS_1_1.dist_decay = coder.typeof(0,[1192 1192]);
ARGS_1_1.distance = coder.typeof(0,[1192 1192]);
ARGS_1_1.agreement = coder.typeof(0,[1192 1192   6]);
ARGS_1_1.axes_range = coder.typeof(0,[1 4]);
ARGS_1_1_NB = struct;
ARGS_1_1_NB.NBind = coder.typeof(0,[1192   1]);
ARGS_1_1_NB.NBpos_x = coder.typeof(0,[1192   1]);
ARGS_1_1_NB.NBpos_y = coder.typeof(0,[1192   1]);
ARGS_1_1_NB.NBang = coder.typeof(0,[1192   1]);
ARGS_1_1_NB.NBdx = coder.typeof(0,[1192   1]);
ARGS_1_1_NB.NBdy = coder.typeof(0,[1192   1]);
ARGS_1_1_NB.NBcolor_norm = coder.typeof(0,[1192   1]);
ARGS_1_1.NB = coder.typeof(ARGS_1_1_NB,[1 801]);
ARGS{1}{1} = coder.typeof(ARGS_1_1);
ARGS_1_2 = struct;
ARGS_1_2.initial_bown = coder.typeof(0);
ARGS_1_2.space_constant = coder.typeof(0);
ARGS_1_2.agreement_combo = coder.typeof(0,[1 3]);
ARGS_1_2.bown_params = coder.typeof(0,[1 7]);
ARGS_1_2.convergence_lambda = coder.typeof(0);
ARGS_1_2.max_iter = coder.typeof(0);
ARGS_1_2.Knear = coder.typeof(0);
ARGS_1_2.weightLCL = coder.typeof(0);
ARGS_1_2.weightGBL = coder.typeof(0);
ARGS_1_2.linearAngTh = coder.typeof(0);
ARGS_1_2.distLCL = coder.typeof(0);
ARGS{1}{2} = coder.typeof(ARGS_1_2);

%% Invoke MATLAB Coder.
cd(strcat(pwd,'/disc'));
codegen -config cfg disc_compute_bown -args ARGS{1}
cd(main_folder)

%% generate preferences file from preferences_default
% create user preferences file
disp('>>> Generating user preferences file and default folder structure')
mkdir output
copyfile('preferences_default.m','preferences_user.m')
disp('> To change output and data folder destinations you can edit preferences_user later')
disp('> Please refrain from editing preferences_default')

%% generate parameters file from disc_params_default
% create user preferences file
disp('>>> Generating user params file and default folder structure')
copyfile('disc/disc_params_default.m','disc/disc_params_user.m')
disp('> To change any parameters of the model use disc_params_user.m')
disp('> Please refrain from editing disc_params_default as it contains the original parameters used in the paper.')

%% creating template file
disp('>>> Creating run_disc_main file from run_disc_main_example')
copyfile('run_disc_main_example.m','run_disc_main.m')
disp('> Please refrain from using run_disc_main_example')
disp('> Feel free to edit run_disc_main or any copies you make of it')

addpath(genpath(main_folder));