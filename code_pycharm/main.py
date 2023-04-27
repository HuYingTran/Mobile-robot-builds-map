import sys, pygame
import openpyxl
import time
from pygame.locals import*

import time
import serial
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np

# --------------------- excel
# wb = openpyxl.load_workbook('./Book1.xlsx')
# sheet_copy = wb.copy_worksheet(wb['Sheet1'])
# sheet = wb['Sheet1 Copy']

# --------- tao cong arduino
arduino = serial.Serial('COM10', 115200)
time.sleep(5)
s = str("quet")
arduino.write(s.encode())
print("bd")

ly = 0.13  # mm khoang cach hai banh
r = 0.07  # mm
# --------------------- vi tri xuat phat
i = 0
x = 2
y = 2
q = 0#np.pi
pi = np.pi/180
s = r*np.pi/30
dt = 0.1 # ms
J = np.array([[0.5,        0.5],  # ma tran chuyen vi
                    [0.5/ly, -0.5/ly]])
z = 200 # he so zoom
width = 1000  # 10m --> 100dv = 1m, 0.1dv = 1mm
height = 800  # 8m
screen_color = (128, 128, 128)
red_color = (220, 0, 0)
line_color = (255, 255, 255)
obs_color = (0, 0, 0)
screen = pygame.display.set_mode((width, height))
screen.fill(screen_color)
pygame.display.flip()



while True:
    pygame.event.get()
    while arduino.inWaiting() == 0:
        # wb.save('./Book1.xlsx')
        # wb.close()
        pass
    ardStr = arduino.readline().decode('utf-8').rstrip()
    if ardStr == "end":
        # wb.save('./Book1.xlsx')
        # wb.close()
        break
    ardList = ardStr.split("-")
    #print(ardList)
    oemga_t = float(ardList[0])*s
    omega_p = float(ardList[1])*s
    omega = np.array([[oemga_t], [omega_p]])
    pos = (float(ardList[2])-90)*pi
    kc = float(ardList[3])/1000

    zeta = J.dot(omega)
    v_x = zeta[0]*1.8

    q = zeta[1] * dt + q              # update vi tri xe
    x = x + v_x * np.cos(q)*dt
    y = y + v_x * np.sin(q)*dt
    print(str(x)+"----"+str(y))

    x_c = x + kc*np.cos(pos+q)
    y_c = y + kc*np.sin(pos+q)

    pygame.draw.line(screen, red_color, (int(z*x), int(z*y)), (int(z*x_c), int(z*y_c)), 3) # -------- black
    if kc < 0.8:
        pygame.draw.line(screen, obs_color, (int(z*x_c), int(z*y_c)),(int(z*x_c)+2, int(z*y_c)+2), 8) # ------ black
    pygame.display.flip()
    pygame.draw.line(screen, line_color, (int(z * x), int(z * y)),(int(z * x_c)-2, int(z * y_c)-2), 5) # -------- while
    #print(zeta)
    # i = i + 1
    # sheet["A" + str(i)] = float(x_c)
    # sheet["B" + str(i)] = float(y_c)

while True:
    for events in pygame.event.get():
        if events.type == QUIT:
            sys.exit(0)