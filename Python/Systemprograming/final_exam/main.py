import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic
import numpy as np
import cv2


class MyWindow(QMainWindow):
    IMG_PATH = ''
    filename = ""
    g_open = 0
    g_new_image = 0
    resize_img = ''
    background_LABEL = 1
    object_LABEL = 2
    value = 0
    change = 0

    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi("Remove_backgrounds.ui", self)
        self.best = None
        self.setup_ui()

    def setup_ui(self):
        self.actionOpen.triggered.connect(self.open_file)
        self.actionSave.triggered.connect(self.save_image)

        self.best = QButtonGroup()
        self.best.addButton(self.bigben)
        self.best.addButton(self.cat)
        self.best.addButton(self.duck)
        self.best.addButton(self.tomato)
        self.best.addButton(self.trafficlight)
        self.best.buttonPressed.connect(self.select_images)

        self.slider_1.setMinimum(0)
        self.slider_1.setMaximum(255)
        self.slider_1.valueChanged.connect(self.change_value)

    def open_file(self):
        MyWindow.filename = 0
        MyWindow.filename = QFileDialog.getOpenFileName(filter="image files (*.jpg *.png)")
        print(MyWindow.filename[0])
        if MyWindow.filename[0]:
            MyWindow.g_open = 1
            filename = MyWindow.filename[0]
            src_img = cv2.imread(filename)
            if MyWindow.filename[0].find('BigBen.jpg') < 0:
                MyWindow.resize_img = cv2.resize(src_img, dsize=(0, 0), fx=0.6, fy=0.6)
            else:
                MyWindow.resize_img = cv2.resize(src_img, dsize=(0, 0), fx=0.2, fy=0.2)
            cv2.destroyAllWindows()
            cv2.imshow(filename, MyWindow.resize_img)
            cv2.waitKey()
        else:
            cv2.destroyAllWindows()
            MyWindow.g_open = 0
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def save_image(self):
        if MyWindow.g_open:
            filename = QFileDialog.getSaveFileName(filter="image files (*.jpg *.png)")
            filename = filename[0]
            cv2.imwrite(filename, MyWindow.g_new_image)
            QMessageBox.information(self, '안내', '파일이 저장되었습니다.')
        else:
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def change_value(self, size):
        if MyWindow.g_open:
            if self.slider_1.valueChanged:
                self.value_lcd.setSegmentStyle(2)
                self.value_lcd.display(size)
                MyWindow.value = size
                MyWindow.change = 1
        else:
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def select_images(self, radio_button):
        if MyWindow.g_open:
            filename = MyWindow.filename[0]
            new_img = MyWindow.resize_img.copy()
            if MyWindow.change == 1:
                MyWindow.change = 0
                self.myWindow_change(new_img, filename, radio_button)
            else:
                self.myWindow_not_change(new_img, filename, radio_button)
        else:
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def myWindow_change(self, new_img, filename, radio_button):
        value = MyWindow.value
        if radio_button is self.bigben:
            self.bigben_Remove_backgrounds(new_img, filename, value)
        elif radio_button is self.cat:
            self.cat_Remove_backgrounds(new_img, filename, value)
        elif radio_button is self.duck:
            self.duck_Remove_backgrounds(new_img, filename, value)
        elif radio_button is self.tomato:
            self.tomato_Remove_backgrounds(new_img, filename, value)
        elif radio_button is self.trafficlight:
            self.trafficlight_Remove_backgrounds(new_img, filename, value)
        else:
            QMessageBox.information(self, 'Warning', '오류가 발생하였습니다.')

    def myWindow_not_change(self, new_img, filename, radio_button):
        if radio_button is self.bigben:
            self.bigben_Remove_backgrounds(new_img, filename, value=167)
        elif radio_button is self.cat:
            self.cat_Remove_backgrounds(new_img, filename, value=99)
        elif radio_button is self.duck:
            self.duck_Remove_backgrounds(new_img, filename, value=111)
        elif radio_button is self.tomato:
            self.tomato_Remove_backgrounds(new_img, filename, value=80)
        elif radio_button is self.trafficlight:
            self.trafficlight_Remove_backgrounds(new_img, filename, value=61)
        else:
            QMessageBox.information(self, 'Warning', '오류가 발생하였습니다.')

    def bigben_Remove_backgrounds(self, new_img, filename, value):
        print(self.value)
        blue, green, red = cv2.split(new_img)
        ret, binary = cv2.threshold(blue, value, 255, cv2.THRESH_BINARY)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        app_sky = cv2.erode(binary, kernel, iterations=3)
        app_ben = cv2.dilate(binary, kernel, iterations=1)
        markers = np.zeros(blue.shape, dtype=np.int32)
        markers[app_sky > 0] = MyWindow.background_LABEL
        markers[app_ben == 0] = MyWindow.object_LABEL
        markers = cv2.watershed(new_img, markers)
        labelimg = np.zeros_like(new_img)
        labelimg[markers == MyWindow.background_LABEL, :] = (255, 255, 255)
        labelimg[markers == MyWindow.object_LABEL, :] = new_img[markers == MyWindow.object_LABEL, :]
        MyWindow.g_new_image = labelimg
        cv2.imshow(filename, labelimg)
        cv2.waitKey()

    def cat_Remove_backgrounds(self, new_img, filename, value):
        print(self.value)
        blue, green, red = cv2.split(new_img)
        ret, binary = cv2.threshold(red, value, 255, cv2.THRESH_BINARY)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        app_forest = cv2.erode(binary, kernel, iterations=20)
        app_cat = cv2.dilate(binary, kernel, iterations=3)
        markers = np.zeros(blue.shape, dtype=np.int32)
        markers[app_forest > 0] = MyWindow.background_LABEL
        markers[app_cat == 0] = MyWindow.object_LABEL
        markers = cv2.watershed(new_img, markers)
        labelimg = np.zeros_like(new_img)
        labelimg[markers == MyWindow.object_LABEL, :] = (255, 255, 255)
        labelimg[markers == MyWindow.background_LABEL, :] = new_img[markers == MyWindow.background_LABEL, :]
        MyWindow.g_new_image = labelimg
        cv2.imshow(filename, labelimg)
        cv2.waitKey()

    def duck_Remove_backgrounds(self, new_img, filename, value):
        print(self.value)
        blue, green, red = cv2.split(new_img)
        ret, binary = cv2.threshold(red, value, 255, cv2.THRESH_BINARY)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        app_grass = cv2.erode(binary, kernel, iterations=1)
        app_duck = cv2.dilate(binary, kernel, iterations=3)
        markers = np.zeros(blue.shape, dtype=np.int32)
        markers[app_grass > 0] = MyWindow.background_LABEL
        markers[app_duck == 0] = MyWindow.object_LABEL
        markers = cv2.watershed(new_img, markers)
        labelimg = np.zeros_like(new_img)
        labelimg[markers == MyWindow.object_LABEL, :] = (255, 255, 255)
        labelimg[markers == MyWindow.background_LABEL, :] = new_img[markers == MyWindow.background_LABEL, :]
        MyWindow.g_new_image = labelimg
        cv2.imshow(filename, labelimg)
        cv2.waitKey()

    def tomato_Remove_backgrounds(self, new_img, filename, value):
        print(self.value)
        blue, green, red = cv2.split(new_img)
        ret, binary = cv2.threshold(green, value, 255, cv2.THRESH_BINARY)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        app_background = cv2.erode(binary, kernel, iterations=50)
        app_tomato = cv2.dilate(binary, kernel, iterations=1)
        markers = np.zeros(blue.shape, dtype=np.int32)
        markers[app_background > 0] = MyWindow.background_LABEL
        markers[app_tomato == 0] = MyWindow.object_LABEL
        markers = cv2.watershed(new_img, markers)
        labelimg = np.zeros_like(new_img)
        labelimg[markers == MyWindow.background_LABEL, :] = (255, 255, 255)
        labelimg[markers == MyWindow.object_LABEL, :] = new_img[markers == MyWindow.object_LABEL, :]
        MyWindow.g_new_image = labelimg
        cv2.imshow(filename, labelimg)
        cv2.waitKey()

    def trafficlight_Remove_backgrounds(self, new_img, filename, value):
        print(self.value)
        blue, green, red = cv2.split(new_img)
        ret, binary = cv2.threshold(red, value, 255, cv2.THRESH_BINARY)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        app_background = cv2.erode(binary, kernel, iterations=1)
        app_trafficlight = cv2.dilate(binary, kernel, iterations=9)
        markers = np.zeros(blue.shape, dtype=np.int32)
        markers[app_background > 0] = MyWindow.background_LABEL
        markers[app_trafficlight == 0] = MyWindow.object_LABEL
        markers = cv2.watershed(new_img, markers)
        labelimg = np.zeros_like(new_img)
        labelimg[markers == MyWindow.background_LABEL, :] = (255, 255, 255)
        labelimg[markers == MyWindow.object_LABEL, :] = new_img[markers == MyWindow.object_LABEL, :]
        MyWindow.g_new_image = labelimg
        cv2.imshow(filename, labelimg)
        cv2.waitKey()


def main():
    app = QApplication(sys.argv)
    editor = MyWindow()
    editor.show()
    app.exec_()


if __name__ == "__main__":
    main()
