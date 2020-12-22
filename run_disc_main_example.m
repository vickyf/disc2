%RUN_DISC_MAIN - run the disc model
%
% Synopsis
%   run_disc_main
%
% Description
%   Code to run the disc model. It will first load default preferences and
%   parameters. Below you can change these parameters depending on your
%   needs.
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

%% set preferces and parameters

% get folder preferences
preferences_user;

% get default parameters
DiscParams   = disc_params_user();
ImportParams = import_params_default();

% original model: weightLCL=0
% augmented model: weightLCL>0 (default weightLCL=0.1)
DiscParams.weightLCL = 0;

% file name of the figure to process
stim_name = "I800_oval.png";

%% Run the model

% run the model and get output
disc_output = disc_main(stim_name,DiscParams,ImportParams,Prefs);

%% show results

% show result of converged model
disc_show_results(disc_output)

% show timecourse results
disc_show_timecourse( disc_output, 'scale', 10, 'sparsity', .5)