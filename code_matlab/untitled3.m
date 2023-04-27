arduinoObj = arduino("COM10",9600);

serialdevObj = device(arduinoObj,'SerialPort',1,'BaudRate', 115200, 'DataBits',8, 'StopBits', 1, 'Parity', 'even')
write(serialdevObj,256,'uint16');
numBytes = serialdevObj.NumBytesAvailable
read(serialdevObj,1,'uint16')