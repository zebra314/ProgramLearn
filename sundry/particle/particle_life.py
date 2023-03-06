## A simple Python port - You need: pip install pygame. Note the code here is not efficient but it's made to be educational and easy
import pygame
import random
from time import time

'''
negative 吸引 
positive 分散
'''
atoms=[]
window_size = 600
pygame.init()
window = pygame.display.set_mode((window_size, window_size))
my_font = pygame.font.SysFont("arial",16)

def draw(surface, x, y, color, size):
    for i in range(0, size):
        pygame.draw.line(surface, color, (x, y-1), (x, y+2), abs(size))
               
def atom(x, y, c):
    return {"x": x, "y": y, "vx": 0, "vy": 0, "color": c}

def randomxy():
    return round(random.random()*(window_size-100) + 1)

def create(number, color):
    group = []
    for i in range(number):
        group.append(atom(randomxy()+50, randomxy()+50, color))
        atoms.append((group[i]))
    return group

def rule(atoms1, atoms2, g):
    for i in range(len(atoms1)):
        fx = 0
        fy = 0
        for j in range(len(atoms2)):
            a = atoms1[i]
            b = atoms2[j]
            dx = a["x"] - b["x"]
            dy = a["y"] - b["y"]
            d = (dx*dx + dy*dy)**0.5
            if( d > 0 and d < 80):
                F = g/d
                fx += F*dx
                fy += F*dy
        a["vx"] = (a["vx"] + fx)*0.5
        a["vy"] = (a["vy"] + fy)*0.5
        a["x"] += a["vx"]
        a["y"] += a["vy"]
        if(a["x"] <= 50):
            a["vx"] = -1*(a["vx"]+5*(a["vx"]/abs( a["vx"]+1))) 
            a["x"] = 51
        elif( a["x"] >= (window_size-50)):
            a["vx"] = -1*(a["vx"]+5*(a["vx"]/abs( a["vx"]+1))) 
            a["x"] = window_size-49
        if(a["y"] <= 50 ):
            a["y"] = 51
            a["vy"] = -1*(a["vy"]+5*(abs(a["vy"])/ (a["vy"]+1))) 
        elif(a["y"] >= (window_size-50)):
            a["vy"] = -1*(a["vy"]+5*(abs(a["vy"])/(a["vy"]+1))) 
            a["y"] = window_size-49      


stage = 1
time_start = 0.0
def stager(atoms):
    
    putxt = ''
    x_avg = 0
    y_avg = 0
    for i in range(len(atoms)):
        a = atoms[i]
        x_avg += a["x"] 
        y_avg += a["y"] 
    x_avg = x_avg/len(atoms)
    y_avg = y_avg/len(atoms)

    total = 0
    for i in range(len(atoms)):
        dx = a["x"] - x_avg
        dy = a["y"] - y_avg
        d = (dx*dx + dy*dy)**0.5
        if( d > 0 and d < 10):
            total = total + 1
    
    global stage 
    global time_start 
    putxt = 'generation: ' + str(int((stage-1)/2)) + ' '
    if(stage%2 == 1):
        if(total < 50):
            putxt = putxt + 'status :normal'
            time_start = time() 
        elif total > 50 and (time() - time_start) < 10.0 :
            putxt = putxt + 'status: ready for division '
        elif total > 50 and (time() - time_start) > 10.0 : 
            stage = stage + 1
            time_start = time() 
    elif(stage%2 == 0):
        if (time() - time_start) > 0.35 :
            stage = stage + 1
            time_start = 0.0
            putxt = putxt + 'status: done division '
        else :
            putxt = putxt + 'status: process division ' # + str(5 -time() + time_start)

    text = my_font.render(putxt, True, (0, 255, 0), (0, 0, 128))
    textRect = text.get_rect()
    window.blit(text, textRect)


blue = create(60, "blue")  # core surrounding
yellow = create(200, "yellow")
red = create(80, "red") # cell surrounding
green = create(200, "green") # core
white = create(200, "white")

# white = create(100, "white")
# blue = create(100, "blue")  # core surrounding
# red = create(100, "red") # cell surrounding
# green = create(100, "green") # core

run = True
while run:
    window.fill(0)
    if (stage%2) == 1: # normal
        rule(yellow, yellow, -0.13) # 0.09
        rule(yellow, green, -1.7) # -1.1
        rule(green, green, -1) # -2
        rule(green, red, -0.8) # -1.1
        rule(yellow, red, 0.5) # 0.4
        rule(blue, blue, -0.05)
        rule(green, blue, -0.1)
        rule(red, blue, -0.06)
        rule(yellow, blue, 0.3)
        rule(red, red, -0.35)
        rule(white, white, 0.0)
    elif (stage%2) == 0: # division
        rule(yellow, yellow, 10)
        rule(yellow, green, -1.1)
        rule(green, green, 5)
        rule(green, red, -1.8)
        rule(yellow, red, 0.4)
        rule(blue, blue, 8)
        rule(green, blue, -1.5)
        rule(red, blue, 2)
        rule(yellow, blue, 0.3)
        rule(red, red, 7)
        rule(white, white, 10)
    
    rule(white, green, -0.005)
    rule(white, yellow, 0.04)
    rule(white, red, 0.01)
    rule(white, blue, 0.05)
    

    stager(red)

    # rule(green, green, 11)
    # rule(green, red, 5)
    # rule(green, white, 17)
    # rule(green, blue, -5)

    # rule(red, red, -50)
    # rule(red, green, 35.5)
    # rule(red, white, -4)
    # rule(red, blue, 0)

    # rule(white, white, -6.5)
    # rule(white, red, 4)
    # rule(white, green, -8.5)
    # rule(white, blue, 4)

    # rule(blue, blue, 14)
    # rule(blue, white, 4)
    # rule(blue, red, 22)
    # rule(blue, green, -2)

    if(len(red)<80):
        a = 80 - len(red)
        red = create(a, "red") # cell surrounding

    for i in range(len(atoms)):
        draw(window,  atoms[i]["x"], atoms[i]["y"], atoms[i]["color"], 3)
        
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    pygame.display.flip()
pygame.quit()
exit()
