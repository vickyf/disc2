function [DiscOutput] = disc_compute_agreement( DiscOutput,DiscParams )
% DISC_COMPUTE_AGREEMENT - computes if nodes are in agreement
%
% Synopsis
%   [ DiscOutput ] = disc_compute_agreement( DiscOutput,DiscParams )
%
% Description
%   Based on the original DISC code by Naoki Kogo extended for the use
%   cases and theories behind DISC2.
%
% Inputs ([]s are optional)
%   (struct)    DiscOutput
%
% Outputs ([]s are optional)
%   (struct)    DiscOutput
%   (struct)    DiscParams
%
% Examples
%   <Example Code>
%
% See also
%   disc_main, disc_params_default, disc_compute_bown
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

%% compute pairwise distances for graded interaction

for i = 1:DiscOutput.num_nodes/2
    for j = i+1:DiscOutput.num_nodes/2
        % compute the graded interaction -- the further away the less
        % influence two nodes with assert.
        distanceTemp = sqrt((DiscOutput.pos_x(i)-DiscOutput.pos_x(j))^2 ...
            +(DiscOutput.pos_y(i)-DiscOutput.pos_y(j))^2);
        DiscOutput.distance(i,j) = distanceTemp;
        DiscOutput.dist_decay(i,j) = exp(-distanceTemp/DiscParams.space_constant);
        
        % reflect over diagonal to grab the other side
        DiscOutput.distance(j,i) = DiscOutput.distance(i,j);
        DiscOutput.dist_decay(j,i) = DiscOutput.dist_decay(i,j);
    end
end

% the full matrix contains four blocks of the same configuration:
DiscOutput.distance(DiscOutput.num_nodes/2+1:end,1:DiscOutput.num_nodes/2)       = DiscOutput.distance(1:DiscOutput.num_nodes/2,1:DiscOutput.num_nodes/2);
DiscOutput.distance(1:DiscOutput.num_nodes/2,DiscOutput.num_nodes/2+1:end)       = DiscOutput.distance(1:DiscOutput.num_nodes/2,1:DiscOutput.num_nodes/2);
DiscOutput.distance(DiscOutput.num_nodes/2+1:end,DiscOutput.num_nodes/2+1:end)   = DiscOutput.distance(1:DiscOutput.num_nodes/2,1:DiscOutput.num_nodes/2);

DiscOutput.dist_decay(DiscOutput.num_nodes/2+1:end,1:DiscOutput.num_nodes/2)     = DiscOutput.dist_decay(1:DiscOutput.num_nodes/2,1:DiscOutput.num_nodes/2);
DiscOutput.dist_decay(1:DiscOutput.num_nodes/2,DiscOutput.num_nodes/2+1:end)     = DiscOutput.dist_decay(1:DiscOutput.num_nodes/2,1:DiscOutput.num_nodes/2);
DiscOutput.dist_decay(DiscOutput.num_nodes/2+1:end,DiscOutput.num_nodes/2+1:end) = DiscOutput.dist_decay(1:DiscOutput.num_nodes/2,1:DiscOutput.num_nodes/2);


%% compute orientation based correspondence

for i = 1:DiscOutput.num_nodes 
    for j = i+1:DiscOutput.num_nodes
        
        % same position but opposite polarity:
        if j ~= DiscOutput.num_nodes/2+i
            
            % get normalized vector going from node i to node j
            vec_i2j = [DiscOutput.pos_x(j)-DiscOutput.pos_x(i),DiscOutput.pos_y(j)-DiscOutput.pos_y(i)];
            norm_i2j = vec_i2j./norm(vec_i2j);

            % compute angles between connecting vector and each bown direction
            vecprev_i = [DiscOutput.dx(i),DiscOutput.dy(i)];
            vecprev_j = [DiscOutput.dx(j),DiscOutput.dy(j)];
            alpha_i = acos(complex(vecprev_i*norm_i2j')) / (norm(vecprev_i)*norm(norm_i2j));
            alpha_j = acos(complex(vecprev_j*norm_i2j')) / (norm(vecprev_j)*norm(norm_i2j));

            if isnan(alpha_i)
                disp('nan');
            end

            % get the sign of the orientation through the crossproduct
            % sometimes the sign=0 because cp(3)=0, exclude those cases.
            cp = vecprev_i(1)*norm_i2j(2) - vecprev_i(2)*norm_i2j(1);
            if sign(cp); alpha_i = sign(cp)*alpha_i; end     
            cp = vecprev_j(1)*norm_i2j(2) - vecprev_j(2)*norm_i2j(1);
            if sign(cp); alpha_j = sign(cp)*alpha_j; end

            % above node i
            if alpha_i>-pi/2 && alpha_i<pi/2
                % and norm of j is facing away from i
                if alpha_j>=-pi/2 && alpha_j<=pi/2
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(4);
                % and norm of j is facing i
                else
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(3);
                end
            % if alligned
            elseif abs(alpha_i) == pi/2
                % collinear with same polarity
                if alpha_i == alpha_j
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(1);
                % collinear with opposite polarity
                elseif alpha_i ~= alpha_j && abs(alpha_j) == pi/2
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(2);
                % I do not feel comfortable with this part in the original code
                else
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(7);
                end
            % below node i
            else
                % and norm of j is facing i
                if alpha_j>-pi/2 && alpha_j<pi/2
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(5);
                % and norm of j is facing away from i
                else
                    DiscOutput.agreement(i,j,1) = DiscParams.bown_params(6);
                end 
            end

            % fill out reflection of the matrix for later use
            DiscOutput.agreement(j,i,1) = DiscOutput.agreement(i,j,1);
        
        end
    end
end


%% compute luminance based agreements: same polarity
% that is the luminance of the region towards which the arrow is pointing

DiscOutput.agreement(:,:,2) = ...
    repmat(DiscOutput.color_norm',1,DiscOutput.num_nodes )==repmat(DiscOutput.color_norm,DiscOutput.num_nodes ,1);


%% compute luminance based agreements: opposite polarity
% that is the luminance of the region from which the arrow is pointing

DiscOutput.agreement(:,:,3) = ...
    repmat(DiscOutput.color_norm'+DiscOutput.color_contrast',1,DiscOutput.num_nodes )==repmat(DiscOutput.color_norm+DiscOutput.color_contrast,DiscOutput.num_nodes ,1);


%% compute luminance based agreements: contrast

DiscOutput.agreement(:,:,4) = ...
    repmat(DiscOutput.color_contrast',1,DiscOutput.num_nodes )==repmat(DiscOutput.color_contrast,DiscOutput.num_nodes ,1);

%% compute neighbor nodes agreements based on colinearity
% that is the immediate neighbor with angle difference less than linearAngTh
% the agreement is already computed by NieghboringPointsFinder
% This is used for the augmented model

k = DiscParams.Knear;
linearAngTh=DiscParams.linearAngTh;
linearAngThPi = linearAngTh/180*pi;
linearAngCos = cos(linearAngThPi);

neighborDbl = DiscOutput.NB;
for iK=1:k   
    tempNeighborPairs = neighborDbl(iK);
    indNB = tempNeighborPairs.NBind;
    for i = 1:DiscOutput.num_nodes 
        j = indNB(i);
                
        % same position but opposite polarity:
        if (j ~= i)&&(j ~= i + DiscOutput.num_nodes/2)&&(j ~= i - DiscOutput.num_nodes/2)

            pos_xi = DiscOutput.pos_x(i);
            pos_yi = DiscOutput.pos_y(i);

            pos_xj = DiscOutput.pos_x(j);
            pos_yj = DiscOutput.pos_y(j);

            dxi = DiscOutput.dx(i);
            dyi = DiscOutput.dy(i);

            dxj = DiscOutput.dx(j);
            dyj = DiscOutput.dy(j);

            % get normalized vector going from node i to node j
            vec_i2j = [pos_xj-pos_xi,pos_yj-pos_yi];
            norm_i2j = vec_i2j./norm(vec_i2j);

            % compute angles between connecting vector and each bown direction        
            vecprev_i = [dxi,dyi];
            vecprev_j = [dxj,dyj];        
            alpha_i = acos(complex(vecprev_i*norm_i2j')) / (norm(vecprev_i)*norm(norm_i2j));        
            alpha_j = acos(complex(vecprev_j*norm_i2j')) / (norm(vecprev_j)*norm(norm_i2j));

            %%%%%%
            if isnan(alpha_i)
                disp('nan');
            end

            % get the sign of the orientation through the crossproduct
            % sometimes the sign=0 because cp(3)=0, exclude those cases.
            cp = vecprev_i(1)*norm_i2j(2) - vecprev_i(2)*norm_i2j(1);
            if sign(cp); alpha_i = sign(cp)*alpha_i; end       
            cp = vecprev_j(1)*norm_i2j(2) - vecprev_j(2)*norm_i2j(1);
            if sign(cp); alpha_j = sign(cp)*alpha_j; end

            % above node i
            if alpha_i>0 && alpha_i<pi
                condI = 1;
            elseif alpha_i<0 && alpha_i>-pi
                condI = -1;
            else
                condI = 0;
            end
            if alpha_j>0 && alpha_j<pi
                condJ = 1;
            elseif alpha_j<0 && alpha_j>-pi
                condJ = -1;
            else
                condJ = 0;
            end
            if condI==1
                if condJ==1
                    DiscOutput.agreement(i,j,5) = (abs(sin(alpha_i))>=linearAngCos)&(abs(sin(alpha_j))>=linearAngCos);
                elseif condJ==-1
                    DiscOutput.agreement(i,j,5) = 0;
                else
                    DiscOutput.agreement(i,j,5) = 0;
                end
            elseif condI==-1
                if condJ==1
                    DiscOutput.agreement(i,j,5) = 0;
                elseif condJ==-1
                    DiscOutput.agreement(i,j,5) = (abs(sin(alpha_i))>=linearAngCos)&(abs(sin(alpha_j))>=linearAngCos);
                else
                    DiscOutput.agreement(i,j,5) = 0;
                end
            else
                DiscOutput.agreement(i,j,5) = 0;
            end            
        end
    end
end
DiscOutput.NB = neighborDbl;

end