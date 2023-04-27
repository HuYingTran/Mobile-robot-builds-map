clear;
% create an arduino object
a = arduino('COM10','uno');     
% start the loop to blink led for 5 seconds

for i=1:20
    writeDigitalPin(a, 'D7', 1);
    pause(0.1);
    writeDigitalPin(a, 'D7', 0);
    pause(0.1);
end

% end communication with arduino

clear a