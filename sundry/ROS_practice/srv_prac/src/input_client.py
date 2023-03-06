#!/usr/bin/env python

import rospy
from std_msgs.msg import Int8

# from package_name.srv
from srv_prac.srv import test,testResponse

def client(msg):
    msg_to_server = rospy.ServiceProxy("srv_practice",test) 
    response = msg_to_server(msg)
    print("Arudino :" , response.response)
    rate.sleep()

if __name__ == '__main__':
    rospy.init_node('input_client')
    rospy.wait_for_service("srv_practice")
    rate = rospy.Rate(1000) # 1000Hz
    while not rospy.is_shutdown():
        try:
            # input the command manually 
            command = int(input("command :"))
            client(command)
        except rospy.ServiceException :
            pass