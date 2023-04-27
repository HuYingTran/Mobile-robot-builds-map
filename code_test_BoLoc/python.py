import serial

ser = srial.Serial("COM25",9600, timeout =1)

def retrieveData():
    ser.write(b'1')
    data = ser.readline().decode('ascii')
    return data

while(True):
    uInput = input("Retrieve data?")
    if uIntput=='1':
        print(retrieveData())
    else:
        ser.write(b'0')