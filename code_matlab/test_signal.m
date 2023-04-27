clear;
% create an arduino object
a = arduino('COM5','uno');     
% start the loop to blink led for 5 seconds

while true
    readVoltage(a, 'A4')
 
end

% end communication with arduino

clear a