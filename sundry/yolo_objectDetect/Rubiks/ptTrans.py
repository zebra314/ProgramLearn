#################################################
##### To convert a .pt file to a .onnx file #####
#################################################

# cd to yolov5 file
# enter the command download into command

# the wrong one (without --simplify will be wrong)
# python export.py --weights C:\Users\kidal\Desktop\cube-solver\main\best.pt --include torchscript onnx

# python export.py --weights # the path of .pt file # --include torchscript onnx

# python export.py --weights C:\Users\kidal\Desktop\cube-solver\main\best.pt --simplify --include onnx

# python export.py --weights yolov5.pt --simplify --include onnx

# to check if the onnx works
# python detect.py --weights C:\Users\kidal\Desktop\cube-solver\main\best.onnx --device 0 --dnn
# python val.py --weights C:\Users\kidal\Desktop\cube-solver\main\best.onnx --dnn

################################
#####  convert pb to pbtxt #####
################################

# import tensorflow.compat.v1 as tf
# tf.disable_v2_behavior()
# from google.protobuf import text_format
# from tensorflow.python.platform import gfile

# def convert_pb_to_pbtxt():
#     """
#     :param filename:
#     :return:
#     """
#     with tf.compat.v2.io.gfile.GFile('C:/Users/kidal/Desktop/cube-solver/main/best.pb', 'rb') as f:
#         graph_def = tf.compat.v1.GraphDef()
#         graph_def.ParseFromString(f.read())
#         tf.import_graph_def(graph_def, name='')
#         tf.train.write_graph(graph_def, 'C:/Users/kidal/Desktop/cube-solver/main/', 'best.pbtxt', as_text=True)
#     return
# # def convert_pbtxt_to_pb():
# #     """Returns a `tf.GraphDef` proto representing the data in the given pbtxt file.
# #     Args:
# #       filename: The name of a file containing a GraphDef pbtxt (text-formatted
# #         `tf.GraphDef` protocol buffer data).
# #     """
# #     with tf.gfile.GFile('C:/Users/kidal/Desktop/cube-solver/main/best.pbtxt') as f:
# #         graph_def = tf.GraphDef()
# #         file_content = f.read()
# #         # Merges the human-readable string in `file_content` into `graph_def`.
# #         text_format.Merge(file_content, graph_def)
# #         tf.train.write_graph(graph_def, '/home/zhy/Documents', 'lanenet.pb', as_text=False)
# #     return
# if __name__ == '__main__':   
#     convert_pb_to_pbtxt()

