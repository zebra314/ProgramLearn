import cv2
from ColorPlot import ColorPlot
from ColorDetection import ColorDetection
from ObjectDetection import ObjectDetection

"""
不是從vscode開啟資夾的話似乎執行不了
"""
if __name__ == '__main__':

    cubeFind = ObjectDetection() # init the object
    colorFind = ColorDetection()
    ColorPlot = ColorPlot()
    cap = cv2.VideoCapture(0)
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break
        if cv2.waitKey(1) & 0xFF == ord('q'): 
            break   
        
        frame_cubeFind, cube_position  = cubeFind(frame) # return frame and coordinates
        # cv2.imshow('cubeFind', frame_cubeFind)

        frame_colorFind, color_info = colorFind(frame, cube_position) # return frame with the cube found and a list containing nine lists [color, position]
        # cv2.imshow('colorFind', frame_colorFind)

        frame_colorPlot = ColorPlot(frame_colorFind, color_info) # return frame with color information on the up left side
        cv2.imshow('frame_colorPlot',frame_colorPlot)

cap.release()