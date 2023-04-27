y = xlsread('E:\DoAn\Sensor\xuLy_soLieu.xlsx',1,'D50:D290')
length(y);
fs = 5;
t=0:1/fs:20-1/fs;
x=fft(y);
length(t)
x=abs(x);
x=[x(1)-39000;x(2:240)]
plot(x(2:240))