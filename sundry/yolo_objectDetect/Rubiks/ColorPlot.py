import numpy as np
import cv2

class ColorPlot:
    """
    This class shows the information on the upper right side of the frame.
    """

    def __init__(self):
        """
        This function called when the class is initialized.
        """

        # the dictionary of color (in type of string) and corresponding RGB code
        self.color2RGB = {'red'     :(52,18,183), 
                          'orange'  :(0, 88, 255), 
                          'yellow'  :(0,213,255), 
                          'blue'    :(173,70,0), 
                          'green'   :(72,155,9), 
                          'white'   :(255,255,255)}
        
        # the position to fill in the color information
        self.fill_position = [((31,31),(54,54)),((31,72),(54,95)),((31,113),(54,136)),
                              ((71,31),(94,54)),((71,72),(94,95)),((71,113),(94,136)), 
                              ((112,31),(135,54)),((112,72),(135,95)),((112,113),(135,136))]

        self.cor = []
    def draw_outline(self, frame):  
        """
        Draws nine rectangles on the upper left side of the frame, which will show the color on the rubik's cube.
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

    # custom function to sort the coordinates of the colors of the cube
    def sort_key_x(self, ele):
        return ele[1][0]
    def sort_key_y(self, ele):
        return ele[1][1]

    def sort_contour(self,cor):
        """
        Sorted the coordinates of the colors of the cube by x first, then sorted by y.
        We expect to get the sorted list in the order down below.
        1 4 7    
        2 5 8
        3 6 9

        :para cor: the list contains the color information, the format: [[color1, cor1],[color2, cor2]....[color9, cor9]]
        :return self.cor: the sorted cor
        """
     
        # 需要存進self.cor[]，因為若沒有完整cor，則不經過sort_contour，直接回傳frame，
        # 這時得顯示最後一次得到得資訊，要有先前儲存的資料；若有完整cor，則重製self.cor[]
        self.cor = []
        temp = []
        cor = sorted(cor, key=self.sort_key_x)

        # 這裡的排序出了問題 導致正常排完會旋轉90度
        for (num,i) in enumerate(cor, 1): 
            temp.append(i)
            if(num%3 == 0):
                temp = sorted(cor, key=self.sort_key_y)
                self.cor.extend(temp)
                temp = []
        
        return self.cor

    def fill_color(self, frame, cor):
        """
        To fill the colors into the hollow black rectangle on the upper right side of the frame
        :para frame: input frame in numpy/list/tuple format. It should be from the colorDetection class and with the cube found if there is a cube
        :para cor: the sorted list contains the color information, the format: [[color1, cor1],[color2, cor2]....[color9, cor9]]
        :return: frame in numpy/list/tuple format and the color info is shown on the upper left side of the frame
        """
        if not len(cor) == 27:
            return frame
        for i in range(9): # 0~8
            cv2.rectangle(frame,self.fill_position[i][0],self.fill_position[i][1],self.color2RGB[cor[i][0]],-1) # cor[i][0]: the color in type of string
        return frame


    def __call__(self, frame, color_info) :
        """
        The function is called when the class is excuted.
        :return: frame
        """
        frame = self.draw_outline(frame)

        # show the data record previously if there is no color info
        if color_info == []:
            frame = self.fill_color(frame, self.cor) 
            return frame

        color_info = self.sort_contour(color_info)
        frame = self.fill_color(frame, color_info)

        return frame