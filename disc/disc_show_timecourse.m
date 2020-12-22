function [] = disc_show_timecourse( DiscOutput,varargin )
% DISC_SHOW_TIMECOURSE - shows the evolution of bown on the stimulus
%
% Synopsis
%   [ output_args ] = disc_show_timecourse( DiscOutput )
%
% Description
%   <Description>
%
% Inputs ([]s are optional)
%   (struct)    DiscOutput
%   (const)     ['scale']       scaling of the quiver plot, DEFAULT=5
%   (const)     ['sparsity']    sparsity of plotting the quiver (i.e. the 
%                               lower the number the less bown signals will
%                               be plot. this to ensure the plot stays
%                               interpretable), DEFAULT=.8 ... [0,1].
%   (str)       ['movie']       export the timecourse as a gif? DEFAULT=0
%   (const)     ['Hz']          Hz at which the movie is recorded,
%                               DEFAULT=60
%
% Outputs ([]s are optional)
%   () 
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

% set default variables
scale = 5;
sparsity = .8;
export_movie = 0;
Hz = 60;

% Checks string inputs.
N = length(varargin);
k = 1;
if mod(N,2)==1
    error('wrong input type. see help disc_show_results')
end

while k<=N
    switch varargin{k}
        case 'scale'
            scale = varargin{k+1};
        case 'sparsity'
            sparsity = varargin{k+1};
        case 'movie'
            export_movie = varargin{k+1};
        case 'Hz'
            Hz = varargin{k+1};
    end
    k = k+2;
end

% set filename for export
if export_movie
    [~,name,~] = fileparts(DiscOutput.stim_name);
    filename = ['timecourse_',name,'.gif'];
end

%% plot bown timecourse

% get sparse idx
sparse_idx = rand(DiscOutput.num_nodes/2,1)<sparsity;
sparse_idx = [sparse_idx;sparse_idx]; % cause we need to show both sides of each node

% set the three colors
colors(:,1) = [0,0,1];
colors(:,2) = [0,0,0];
colors(:,3) = [1,0,0];

figure(202);
for iter = 1:DiscOutput.num_iter+1
    % we will plot in three colors, blue when <.5, red when >.5, and black when
    % =.5
    % get the indices to those three cases.
    idx(:,1) = DiscOutput.bown_timecourse(iter,:)<.5;
    idx(:,2) = DiscOutput.bown_timecourse(iter,:)==.5;
    idx(:,3) = DiscOutput.bown_timecourse(iter,:)>.5;

    clf; set(gca,'box','off'); axis off; set(gcf,'color',[.9,.9,.9])
    hold on
    % plot the stimulus
    scatter(DiscOutput.pos_x(sparse_idx),DiscOutput.pos_y(sparse_idx),20,[.5,.5,.5],'filled')

    % plot the bown signals
    for q = 1:3
        % plot only if there are indices for it (otherwise odd axes)
        if sum(idx(:,q))>0
            quiver(DiscOutput.pos_x(idx(:,q)&sparse_idx),DiscOutput.pos_y(idx(:,q)&sparse_idx),...
                scale*DiscOutput.bown_timecourse(iter,idx(:,q)&sparse_idx).*DiscOutput.dx(idx(:,q)&sparse_idx),...
                scale*DiscOutput.bown_timecourse(iter,idx(:,q)&sparse_idx).*DiscOutput.dy(idx(:,q)&sparse_idx),...
                'AutoScale','off','ShowArrowHead','off', 'Color', colors(:,q));
        end
    end
    axis equal
    axis(DiscOutput.axes_range);
    h = title({strcat('disc model results for <',DiscOutput.stim_name,'>'), ...
        strcat('iteration: ',num2str(iter-1))});
    get(h,'interpreter');
    set(h,'interpreter','none'); % so that underscores dont work latex-wise
    hold off
    
    drawnow
    
    % if we want to save this as a gif (note the more iterations the larger the file!)
    if export_movie
        frame = getframe(202);
        im = frame2im(frame);
        
        [imind,cm] = rgb2ind(im,256);

        if iter == 1
          imwrite(imind,cm,filename,'gif', 'Loopcount',inf,'DelayTime',1/Hz);

        else
          imwrite(imind,cm,filename,'gif','WriteMode','append','DelayTime',1/Hz);
        end
    end
    
end

end

