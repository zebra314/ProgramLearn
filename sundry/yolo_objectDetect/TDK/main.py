import cv2
import threading
from ObjectDetection import ObjectDetection
from Camera import Mointor, Recorder, photoTake


if __name__ == '__main__':
    # Camera settings
    camera_id = 2

    # Init the camera thread
    thread = Mointor(camera_id)
    thread_lock = threading.Lock()
    thread.start()

    # Init the object of image processor
    charFind = ObjectDetection() 
    # recorder = Recorder() 
    # phototake = photoTake()
    # phototake()

    while True:
        if cv2.waitKey(1) & 0xFF == ord('q'):
            thread.Exit()
            break

        # Get the frame from the camera thread
        thread_lock.acquire()
        frame = thread.get_frame()
        thread_lock.release()

        # Processing the img
        frame_charFind, char_position  = charFind(frame) # return frame and coordinates
        cv2.imshow('charFind', frame_charFind)
        # recorder(frame_charFind)

    # # Release the resource
    thread.join()
    # recorder.writer.release()
    cv2.destroyAllWindows()