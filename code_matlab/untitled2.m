bt = Bluetooth('btspp://002106BE98C2',1);
fopen(bt);

for i=1:1:10
    fwrite(bt,'E')
    disp(i)
    pause(0.5);
    disp(fgets(bt))

end 
