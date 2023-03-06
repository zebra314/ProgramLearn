import torch
import numpy as np
import cv2
import time
import mediapipe as mp



"""
1. Given the frame and the cube position, provides the color type and position of the cube 
"""
class ColorDetection:
    """
    Class filt out the color on the cube and plots color in the info box
    """

    # Setup RGB range of the color to detect
    lower_red = np.array([165,190,100],np.uint8) 
    upper_red = np.array([179,255,255],np.uint8)
    lower_ora = np.array([0,190,100],np.uint8) 
    upper_ora = np.array([15,255,255],np.uint8)
    lower_yel = np.array([27,190,100],np.uint8) 
    upper_yel = np.array([54,255,255],np.uint8)
    lower_blu = np.array([91,165,100],np.uint8) 
    upper_blu = np.array([110,255,255],np.uint8)
    lower_gre = np.array([58,165,100],np.uint8) 
    upper_gre = np.array([75,255,255],np.uint8)
    lower_whi = np.array([0,0,130],np.uint8) 
    upper_whi = np.array([179,45,255],np.uint8)

    def __init__(self):
        pass
        # self.frame = ObjectDetection().target_area

    def draw_outline(self, frame):  
        """
        Draws nine rectangles on the top left of the frame, which will show the color on the rubik's cube.
        :return: frame with nine rectangles on the top left side.       
        1 4 7    
        2 5 8
        3 6 9
        """
        cv2.rectangle(frame,(29,29),(56,56),(0,0,0),3) #1
        cv2.rectangle(frame,(29,70),(56,97),(0,0,0),3) #2
        cv2.rectangle(frame,(29,111),(56,138),(0,0,0),3) #3
        cv2.rectangle(frame,(69,29),(96,56),(0,0,0),3) #4
        cv2.rectangle(frame,(69,70),(96,97),(0,0,0),3) #5
        cv2.rectangle(frame,(69,111),(96,138),(0,0,0),3) #6
        cv2.rectangle(frame,(110,29),(137,56),(0,0,0),3) #7
        cv2.rectangle(frame,(110,70),(137,97),(0,0,0),3) #8
        cv2.rectangle(frame,(110,111),(137,138),(0,0,0),3) #9

        return frame

    def color_mask(self, frame):
        # Setup the masks that use to filt the colors
        r_mask = cv2.inRange(frame, lower_red, upper_red) 
        o_mask = cv2.inRange(frame, lower_ora, upper_ora)
        y_mask = cv2.inRange(frame, lower_yel, upper_yel)
        b_mask = cv2.inRange(frame, lower_blu, upper_blu)
        g_mask = cv2.inRange(frame, lower_gre, upper_gre)
        w_mask = cv2.inRange(frame, lower_whi, upper_whi)
    

    
"""
1. boxes the cube on the frame
2. provides the position data of the target
"""

class ObjectDetection:
    """
    Class implements Yolo5 model to make inferences on a webcam usign OpenCV.
    """

    def __init__(self):

        self.model = self.load_model()
        self.classes = self.model.names
        self.device = 'cuda' if torch.cuda.is_available() else 'cpu'
        print('\n\nDevice used: ',self.device,'\n')

    def load_model(self):
        """
        Loads Yolo5 model from the local weight file.
        :return: Trained Pytorch model.
        """
        model = torch.hub.load('ultralytics/yolov5','custom',path = '/Users/kidal/Desktop/cube-solver/best.pt')
        return model


    def score_frame(self, frame):
        """
        Takes a single frame as input, and scores the frame usign yolo5 model
        :param frame: input frame in numpy/list/tuple format.
        :return: Labels and Coordinates of objects detected by mdoel in the frame.
        """
        self.model.to(self.device)
        frame = [frame]
        results = self.model(frame)

        labels, cord = results.xyxyn[0][:, -1], results.xyxyn[0][:, :-1]
        return labels, cord


    def class_to_label(self, x):
        """
        For a given label value, return corresponding string label.
        :param x: numeric label
        :return: corresponding string label
        """
        return self.classes[int(x)]


    def plot_boxes(self, results, frame):
        """
        Takes a frame and its results as input, and plots the bounding boxes and label on the frame.
        Also stores the position info of the target area 
        :param results: contains labels and coordinates predicted by model on the given frame.
        :return: Frame with bounding boxes and labels ploted on it.
        """
        labels, cord = results
        n = len(labels)
        x_shape, y_shape = frame.shape[1], frame.shape[0]

        for i in range(n):
            row = cord[i]
            if row[4] < 0.2:
                continue

            x1, y1, x2, y2 = int(row[0]*x_shape), int(row[1]*y_shape), int(row[2]*x_shape), int(row[3]*y_shape)
            w = abs(x1-x2)
            h = abs(y1-y2)
            bgr = (0, 255, 0)

            if w/h >0.7 and w/h <1.3:
                cv2.rectangle(frame, (x1, y1), (x2, y2), bgr, 2)
                # cv2.putText(frame, self.class_to_label(labels[i]), (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 1.5, bgr)

                # store the position of the target area
                self.target_area = frame[min(y1, y2):min(y1, y2)+h, min(x1, x2):min(x1, x2)+w]

        return frame


    def __call__(self):
        """
        This function is called when class is executed, it runs the loop to read the video 
        and output the result into a new window
        :retuen: void
        """

        cap = cv2.VideoCapture(0)

        while cap.isOpened():
            start_time = time.perf_counter()
            ret, frame = cap.read()
            if not ret:
                break
            results = self.score_frame(frame)
            frame = self.plot_boxes(results, frame)
            
            end_time = time.perf_counter()
            fps = 1/np.round(end_time - start_time, 3)
            # cv2.putText(frame, f'FPS: {int(fps)}', (20,70), cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 255, 0))

            frame = ColorDetection().draw_outline(frame)

            cv2.imshow('img', frame)
            cv2.imshow('target area', self.target_area)

            if cv2.waitKey(1) & 0xFF == ord('q'): 
                break   


# Create a new object and execute.
detection = ObjectDetection()
detection()
