import numpy as np
import cv2
class ColorDetection:
    """
    Given the frame from webcam and the coordinate of the cube, this class 
    returns a frame and a list containing the color information.
    """

    def __init__(self):

        # Setup RGB range of the color to detect 
        # not stable in strong light
        self.lower_red = np.array([115,160,140],np.uint8) 
        self.upper_red = np.array([180,255,255],np.uint8)
        self.lower_ora = np.array([0,160,140],np.uint8) 
        self.upper_ora = np.array([20,255,255],np.uint8)
        self.lower_yel = np.array([25,160,140],np.uint8) 
        self.upper_yel = np.array([55,255,255],np.uint8)
        self.lower_blu = np.array([90,165,100],np.uint8) 
        self.upper_blu = np.array([110,255,255],np.uint8) 
        self.lower_gre = np.array([38,160,60],np.uint8) 
        self.upper_gre = np.array([95,255,255],np.uint8)
        self.lower_whi = np.array([0,0,130],np.uint8) 
        self.upper_whi = np.array([180,45,255],np.uint8)
        self.colorList = ['red', 'orange', 'yellow', 'blue', 'green', 'white']
          
    def BGR2HSV(self, frame):
        """
        Transform the color of the image from BGR to HSV
        :param frame: input frame in numpy/list/tuple format.
        :return: the frame in HSV.
        """
        frame_HSV = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
        return frame_HSV


    def color_mask(self, frame, color):
        """
        Setup the masks that use to filt the colors
        :para frame: input frame in numpy/list/tuple format.
        :para color: the color to be extracted out from the frame.
        :return: the frame only contains the target color.
        """
        frame_mask = []
        if(color == 'red'):
            frame_mask = cv2.inRange(frame, self.lower_red, self.upper_red)
        elif(color == 'orange'):
            frame_mask = cv2.inRange(frame, self.lower_ora, self.upper_ora)
        elif(color == 'yellow'):
            frame_mask = cv2.inRange(frame, self.lower_yel, self.upper_yel)
        elif(color == 'blue'):
            frame_mask = cv2.inRange(frame, self.lower_blu, self.upper_blu)
        elif(color == 'green'):
            frame_mask = cv2.inRange(frame, self.lower_gre, self.upper_gre)
        elif(color == 'white'):
            frame_mask = cv2.inRange(frame, self.lower_whi, self.upper_whi)

        return frame_mask

    def findContours(self, frame):
        """
        Find out all contours of the target color in the frame
        :para frame: input frame in numpy/list/tuple format.
        :return: the coordinates of contours in type of list.
        """
        contours , _ = cv2.findContours(frame,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
        return contours

    def exactContour(self, contours):
        """
        Use some conditions to filt out the target contours.
        :para contours: coordinates of contours in type of list.
        :return: coordinate of the target contours in type of list.
        """
        exact_Contour = []
        for contour in contours :
            _,_,w,h = cv2.boundingRect(contour)
            area = cv2.contourArea(contour)
            ep = 0.005 * cv2.arcLength(contour, True)  # precision
            approx = cv2.approxPolyDP(contour, ep, True)
            if area>100 and w/h >0.9 and w/h <1.1 and len(approx)<40:
                exact_Contour.append(contour)
        
        return exact_Contour
                
    def plotOnCube(self, frame, contour):
        """
        Plot the bounding rectangle on the colors of the cube
        :para frame: input frame in numpy/list/tuple format.
        :para contour: the target contours in type of list.
        :return: the frame which the color blocks has bounding blocks surrounding.
        """

        color_plot = (0, 0, 0) # black
        x, y, w, h = cv2.boundingRect(contour)

        # 我們把魔方從原本的圖片中擷取出來，做顏色和邊塊的篩選，篩選完後會得到顏色資訊和座標
        # 座標是擷取出來後的坐標系，要加上原本的座標(self.x_trans, self.y_trans)做修正，能在原本的圖上的正確位置顯示
        u = int(x+0.2*w + self.x_trans)
        v = int(y+0.2*h + self.y_trans)
        a = int(x+0.8*w + self.x_trans)
        b = int(y+0.8*h + self.y_trans)
        cv2.rectangle(frame, (u,v), (a,b), color_plot, 2)
        coordinate_rec = [u,v] # 回傳長方形中左上角的座標
        return frame, coordinate_rec

    def __call__(self, frame, cord): 
        """
        The function is called when the class is excuted.
        :return: frame_colorFind, color_info [(color1, cord1), (color2, cord2), ....(color9, cord9)]
        """

        self.color_info = []

        # the format of cord : [min(y1, y2), min(y1, y2)+h, min(x1, x2), min(x1, x2)+w]
        # if the cube was not found
        if cord == [0,0,0,0]: 
            return frame, self.color_info

        # extract the target from the original frame
        # use +-3 delete the bounding rectangle we plot on the image in the class of ObjectDetection
        target_frame = frame[cord[0]+3:cord[1]-3, cord[2]+3:cord[3]-3] 

        # recored the coordinate of the colors of the cube in the original frame from webcam
        # for the revision in the plotOnCube function
        self.x_trans = cord[2]+3  
        self.y_trans = cord[0]+3

        target_frame = self.BGR2HSV(target_frame)
        self.color_info = [] # [[color1, cor1],[color2, cor2]....[color9, cor9]]
        for color in self.colorList :
            mask = self.color_mask(target_frame, color) # filt out the color
            contours = self.findContours(mask) # get the contours, single color
            exact_contour = self.exactContour(contours) # the exact contour may be more than one
            for contour in exact_contour :
                frame, cor = self.plotOnCube(frame, contour)
                self.color_info.append([color, cor])

        # 如果傳出的self.color_info 大小不一致 會報錯
        # 但還是不知道為何空的list和長度為九的不會被認定為不一致
        if not len(self.color_info) == 9: 
            self.color_info = []

        return frame ,self.color_info