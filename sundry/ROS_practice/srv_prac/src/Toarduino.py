#!/usr/bin/env python
# this program get the msg sended from client ,which we manually input ,and then send it to arduino


import rospy
from std_msgs.msg import Int8
import serial 
from time import sleep
from srv_prac.srv import test,testResponse 

def callback(request):
    
    # send the msg to arduino
    ser.write(bytes(str(request.request), 'utf-8'))

    print('msg sended , waiting arduino echo...')
    arduino_echo = ''
    while arduino_echo == '' :
        arduino_echo = ser.readline().decode('utf-8').strip()
    # print("Arduino :" , arduino_echo)
    print('arduino echo received')
    print('waiting command...')
        
    # return the response to client
    return testResponse(request.request) 

if __name__ == '__main__':
    rospy.init_node('Toarduino')
    
    # connect to arduino board
    ser = serial.Serial('/dev/ttyUSB0',57600)
    ser.timeout = 3
    print('arduino connected')

    while True:
        try:
            print('waiting command...')

            # if the client send a request , call callback
            rospy.Service('srv_practice',test,callback) 

            # keeps the node from exiting
            rospy.spin() 
            
        except rospy.ROSInterruptException:
            ser.close()
            print('\nend')
            exit()