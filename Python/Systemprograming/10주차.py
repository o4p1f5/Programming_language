# print("#######################################################################")
# import os
# import cv2
# import numpy as np
#
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "spiderman.jpg")
# bgrimg = cv2.imread(filename)
#
# # cv2로 gray
# grayimg1 = cv2.cvtColor(bgrimg, cv2.COLOR_BGR2GRAY)
# # np로 gray
# grayimg2 = np.mean(bgrimg, axis=2).astype(np.uint8)
#
# hsvimg = cv2.cvtColor(bgrimg, cv2.COLOR_BGR2HSV)
#
# # channel 순서 => 색조, 채도, 명도
# channels = np.concatenate([hsvimg[:,:,0], hsvimg[:,:,1], hsvimg[:,:,2]], axis=1)
# cv2.imshow('HRV channels', channels)
# cv2.waitKey()
#
# # 얼굴, 몸 구분
# hueimg = hsvimg[:,:,0]
# valueimg = hsvimg[:,:,2]
#
# faceimg = np.zeros_like(bgrimg)
# # 인덱스에 T/F로 조건을 넣어주면 True인 부분만 출력
# # 색조만 고려해서 이후 RGB는 그대로 따라옴
# # faceimg에서 추출된 부분에 bgrimg의 추출된 부분을 덮어씌움
# faceimg[hueimg < 13, :] = bgrimg[hueimg < 13, :]
#
# bodyimg = np.zeros_like(bgrimg)
# bodyimg[hueimg > 170, :] = bgrimg[hueimg > 170, :]
# bodyimg[(hueimg>100) & (hueimg<130), :] = bgrimg[(hueimg>100) & (hueimg<130), :]
# bodyimg[valueimg>220] = 0 # 배경 제거
#
# segment = np.concatenate([faceimg, bodyimg], axis=1)
# cv2.imshow("segmented image", segment)
# cv2.waitKey()

# print("########################################################################")
# import os
# import cv2
# import numpy as np
#
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "spiderman.jpg")
# bgrimg = cv2.imread(filename)
#
# yuvimg = cv2.cvtColor(bgrimg, cv2.COLOR_BGR2YUV)
# chnnels = np.concatenate([yuvimg[:,:,0],
#                          yuvimg[:,:,1],
#                          yuvimg[:,:,2]], axis=1)
#
# cv2.imshow("YUV image", chnnels)
# cv2.waitKey()

# print("########################################################################")
# import os
# import cv2
# import numpy as np
#
# IMG_PATH = "C:/Systemprograming/sample_imgs"
# filename = os.path.join(IMG_PATH, "sungmo.jpg")
# bgrimg = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
#
# # cv2 이용
# # 180보다 높으면 255로 변경   (입력영상, 경계값, 경계 기준 만족 시 적용될 값, threshold 적용방법)
# ret, binary1 = cv2.threshold(bgrimg, 180, 255, cv2.THRESH_BINARY)
# showimg = np.concatenate([bgrimg, binary1], axis=1)
#
# # np 이용
# binary2 = np.zeros_like(bgrimg)
# binary2[bgrimg < 180] = 0
# binary2[bgrimg >= 180] = 255
#
# cv2.imshow("cv2 Thershold image", showimg)
# cv2.waitKey()
#
# cv2.imshow("np Thershold image", binary2)
# cv2.waitKey()

# print("########################################################################")
# import sys, os
# import cv2
# from PyQt5.QtWidgets import *
# from PyQt5 import uic
# import matplotlib.pylab as plt
#
#
# class MyWindow(QMainWindow):
#     def __init__(self):
#         super().__init__()
#         self.ui = uic.loadUi("threshold.ui", self)
#         self.src_img = None
#         self.res_img = None
#         self.rb_thresh_methods = {self.radioButton_binary: cv2.THRESH_BINARY,
#                                   self.radioButton_binary_inv: cv2.THRESH_BINARY_INV,
#                                   self.radioButton_trunc: cv2.THRESH_TRUNC,
#                                   self.radioButton_tozero: cv2.THRESH_TOZERO,
#                                   self.radioButton_tozero_inv: cv2.THRESH_TOZERO_INV,
#                                   }
#         self.rb_method_group = QButtonGroup()
#         self.sel_thresh_method = cv2.THRESH_BINARY
#         self.sel_thresh_value = 100
#
#         self.rb_adap_methods = {self.radioButton_none: None,
#                                 self.radioButton_otsu: "otsu",
#                                 self.radioButton_mean: "adap_mean",
#                                 self.radioButton_gauss: "adap_gauss"
#                                 }
#         self.rb_adap_group = QButtonGroup()
#         self.sel_adap_method = None
#         self.setup_ui()
#
#     def setup_ui(self):
#         self.actionopen.triggered.connect(self.open_file)
#         self.actionSave.triggered.connect(self.save_file)
#
#         self.radioButton_binary.setChecked(True)
#         self.verticalSlider.setMaximum(255)
#         self.verticalSlider.setMinimum(0)
#         self.verticalSlider.setValue(100)
#
#         for rbutton in self.rb_thresh_methods:
#             self.rb_method_group.addButton(rbutton)
#
#         self.rb_method_group.buttonPressed.connect(self.update_thresh_method)
#         self.verticalSlider.valueChanged.connect(self.update_thresh_value)
#
#         self.pushButton_thresh_type.clicked.connect(self.show_all_types)
#
#         for rbutton in self.rb_adap_methods:
#             self.rb_adap_group.addButton(rbutton)
#             self.rb_adap_group.buttonPressed.connect(self.update_adap_method)
#
#         self.pushButton_adap_methods.clicked.connect(self.show_adap_methods)
#
#     def open_file(self):
#         filename = QFileDialog.getOpenFileName(filter="JPG files (*.jpg)", directory="C:/Systemprograming/sample_imgs")
#         filename = filename[0]
#         print("open file:", filename)
#         if not filename:
#             return
#         self.src_img = cv2.imread(filename, cv2.IMREAD_GRAYSCALE)
#         cv2.imshow("original", self.src_img)
#         cv2.waitKey(1)
#
#     def save_file(self):
#         filename = QFileDialog.getSaveFileName(filter="JPG files (*.jpg)")
#         filename = filename[0]
#         print("save file:", filename)
#         if not filename or self.res_img is None:
#             return
#         cv2.imwrite(filename, self.res_img)
#
#     def update_thresh_method(self, rbutton):
#         self.sel_thresh_method = self.rb_thresh_methods[rbutton]
#         self.update_result()
#
#     def update_thresh_value(self, value):
#         self.sel_thresh_value = value
#         self.update_result()
#
#     def update_adap_method(self, rbutton):
#         self.sel_adap_method = self.rb_adap_methods[rbutton]
#         self.update_result()
#
#     def update_result(self):
#         # # ret, self.res_img = cv2.threshold(self.src_img, self.sel_thresh_value, 255, self.sel_thresh_method)
#         # ret, res_img = cv2.threshold(self.src_img, self.sel_thresh_value, 255, self.sel_thresh_method | cv2.THRESH_OTSU)
#         # cv2.imshow("result image", self.res_img)
#         # cv2.waitKey(1)
#
#         if self.sel_adap_method is None:
#             ret, self.res_img = cv2.threshold(self.src_img,
#                                               self.sel_thresh_value, 255, self.sel_thresh_method)
#         elif self.sel_adap_method == "otsu":
#             ret, self.res_img = cv2.threshold(self.src_img,
#                                               self.sel_thresh_value, 255, self.sel_thresh_method | cv2.THRESH_OTSU)
#             print("otsu selected threshold:", ret)
#         elif self.sel_adap_method == "adap_mean":
#             self.res_img = cv2.adaptiveThreshold(self.src_img, 255,
#                                                  cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 9, 5)
#         elif self.sel_adap_method == "adap_gauss":
#             self.res_img = cv2.adaptiveThreshold(self.src_img, 255,
#                                                  cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 9, 5)
#         cv2.imshow("result image", self.res_img)
#         cv2.waitKey(1)
#
#     def show_all_types(self):
#         threshold = self.verticalSlider.value()
#         imgs = {"ORIGINAL": self.src_img}
#         for rbutton, thresh_method in self.rb_thresh_methods.items():
#             ret, res_binary = cv2.threshold(self.src_img, threshold, 255, thresh_method)
#             imgs[rbutton.text()] = res_binary
#         imgs['TRUNC'][0,0] = 255
#
#         for i, (title, image) in enumerate(imgs.items()):
#             # 2 X 3 # i+1 번째에 사진 삽입
#             plt.subplot(2, 3, i+1)
#             plt.title(title)
#             plt.imshow(image, cmap='gray')
#             plt.xticks([])
#             plt.yticks([])
#         plt.tight_layout()
#         plt.show()
#
#     def show_adap_methods(self):
#         threshold = self.verticalSlider.value()
#         imgs = {"None": self.src_img}
#         ret, imgs["Otsu"] = cv2.threshold(self.src_img, threshold, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
#         imgs["Adaptive_Mean"] = cv2.adaptiveThreshold(self.src_img, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 9, 5)
#         imgs["Adaptive_Gauss"] = cv2.adaptiveThreshold(self.src_img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 9, 5)
#
#         for i, (key, value) in enumerate(imgs.items()):
#             # 2 X 3 # i+1 번째에 사진 삽입
#             plt.subplot(1, 4, i+1)
#             plt.title(key)
#             plt.imshow(value, cmap='gray')
#             plt.xticks([])
#             plt.yticks([])
#         plt.tight_layout()
#         plt.show()
#
#
# def main():
#     app = QApplication(sys.argv)
#     editor = MyWindow()
#     editor.show()
#     app.exec_()
#
#
# if __name__ == "__main__":
#     main()
