%% Kinemaitc simulation of mobile robot
clear all;clc; % lenh xoa man hinh

%% tham so mo phong
dt = 0.1; % buoc nhay
ts = 4.5; % thoi gian mo phong
t = 0:dt:ts; % vector

%% thong so vat ly cua xe
r = 0.03; % ban kinh banh xe
l_x = 0.15;%0.15; % khoang cach banh xe den khung xe
l_y = 0.2;%0.13;

%% vi tri ban dau
x0 = -0.5;
y0 = -0.5;
pos_0 = pi()/2;

eta0 = [x0;y0;pos_0]; % ma tran vi tri ban dau
eta(:,1) = eta0;

%% vong lap - xe di chuyen
for i=1:length(t)
    
    %% input
    omega_1 = 40;
    omega_2 = 45;
    omega = [omega_1;omega_2];

    % ma tran jacobian
    J = (r/2)*[1,     1;
               1/l_y, -1/l_y];
    
    % van toc
    zeta(:,i) = J*omega;
    v_x = zeta(1,i);
    pos = zeta(2,i)*dt+eta(3,i);
    

    eta(:,i+1) = eta(:,i) + [dt*v_x*cos(pos); dt*v_x*sin(pos); dt*zeta(2,i)]; % update vi tri
    
    
end
%% ve bieu do
figure
plot(t,eta(1,1:i),'r-'); % toa do Ox
hold on
plot(t, eta(2,1:i),'b-'); % toa do Oy
xlabel('t,[s]');
ylabel('s,[m]');
yyaxis right
ylabel('\psi,[rad]');
plot(t, eta(3,1:i),'g-'); % goc phi

legend('x,[m]','y,[m]','\psi,[rad]');
set(gca,'fontsize',10);



eta(:,i)
%% hinh anh chuyen dong cua robot
l = 2*(l_y);
w = 2*l_x+0.02;
% toa do 4 diem robot so voi tam robot
mr_co = [-l/2,  l/2, l/2, -l/2, -l/2;           % |-----|
         -w/2, -w/2, w/2,  w/2, -w/2;];         % |_____|

s=-pi()/2:pi()/20:pi()/2;

figure
for i = 1:5:length(t) % robot bat dau di chuyen
    psi = eta(3,i);
    R_psi = [cos(psi),-sin(psi);
           sin(psi),cos(psi);]; % ma tran quay
    v_pos = R_psi*mr_co;
    fill(v_pos(1,:) + eta(1,i),v_pos(2,:)+eta(2,i),'g');
    % backgound
    hold on, grid on;
    
    x=cos(s+psi)+eta(1,i);
    y=sin(s+psi)+eta(2,i);
 
    for j = 1:length(s)
        plot([eta(1,i),x(j)],[eta(2,i),y(j)],'r-');
        hold on
    end
    
    axis([-1 5 -1 5 ]), axis square;
    plot(eta(1,1:i),eta(2,1:i),'b-');
    legend('MR','Path');
    set(gca,'fontsize',10);
    xlabel('x,[m]');ylabel('y,[m]');
    pause(0.1);
    hold off;
end % animation ends here
title('\omega_1=40rad/s, \omega_2=45rad/s ')

         