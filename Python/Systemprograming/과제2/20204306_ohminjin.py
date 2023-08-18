import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic
import os
import cv2


class MyWindow(QMainWindow):
    g_open = 0
    g_comment = ''
    IMG_PATH = ''
    g_red = 0
    g_green = 0
    g_blue = 0
    g_binary = 0
    g_gray = 0
    g_rgb = 0
    g_check = 0
    filename = ""
    g_new_image = 0
    count = 0

    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi("photo_editor.ui", self)
        self.setup_ui()

    def setup_ui(self):
        self.picture.triggered.connect(self.open_picture)

        self.comment.cursorPositionChanged.connect(self.update_comment)
        self.file_position.cursorPositionChanged.connect(self.update_file_position)

        self.color_space = QButtonGroup()
        self.color_space.addButton(self.binary)
        self.color_space.addButton(self.gray)
        self.color_space.addButton(self.rgb)
        self.color_space.buttonPressed.connect(self.change_color_space)

        self.comment_yn = QButtonGroup()
        self.comment_yn.addButton(self.no)
        self.comment_yn.addButton(self.yes)
        self.comment_yn.buttonPressed.connect(self._comment_yn)

        self.red_bar.setMinimum(0)
        self.red_bar.setMaximum(255)
        self.red_bar.valueChanged.connect(self.change_comment_color_red)

        self.green_bar.setMinimum(0)
        self.green_bar.setMaximum(255)
        self.green_bar.valueChanged.connect(self.change_comment_color_green)

        self.blue_bar.setMinimum(0)
        self.blue_bar.setMaximum(255)
        self.blue_bar.valueChanged.connect(self.change_comment_color_blue)

        self.print.clicked.connect(self._print)
        self.save.clicked.connect(self._save)

    def open_picture(self):
        MyWindow.filename = 0
        MyWindow.filename = QFileDialog.getOpenFileName(filter="image files (*.jpg *.png)")

        if MyWindow.filename[0]:
            MyWindow.g_open = 1
            filename = MyWindow.filename[0]
            src_img = cv2.imread(filename)
            cv2.destroyAllWindows()
            cv2.imshow(filename, src_img)
            cv2.waitKey()
        else:
            cv2.destroyAllWindows()
            MyWindow.g_open = 0
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def update_comment(self):
        MyWindow.g_comment = self.comment.text()

    def update_file_position(self):
        MyWindow.IMG_PATH = self.file_position.text()

    def change_color_space(self, radio_button):
        if MyWindow.g_open:
            if radio_button is self.binary:
                MyWindow.g_binary = 1
                MyWindow.g_gray = 0
                MyWindow.g_rgb = 0
            elif radio_button is self.gray:
                MyWindow.g_gray = 1
                MyWindow.g_binary = 0
                MyWindow.g_rgb = 0
            elif radio_button is self.rgb:
                MyWindow.g_rgb = 1
                MyWindow.g_binary = 0
                MyWindow.g_gray = 0
            else:
                QMessageBox.information(self, 'Warning', '오류가 발생하였습니다.')
        else:
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def _comment_yn(self, radio_button):
        if MyWindow.g_rgb:
            if radio_button is self.no:
                MyWindow.g_check = 0
            elif radio_button is self.yes:
                MyWindow.g_check = 1
            else:
                QMessageBox.information(self, 'Warning', '오류가 발생하였습니다.')
        else:
            QMessageBox.information(self, 'Warning', 'color space type이 RGB일 때만 선택이 허용됩니다.')

    def change_comment_color_red(self, size):
        if MyWindow.g_check:
            if self.red_bar.valueChanged:
                self.red_lcdNumber.setSegmentStyle(2)
                self.red_lcdNumber.display(size)
                MyWindow.g_red = size
        else:
            QMessageBox.information(self, 'Warning', '자막 설정을 하지 않았습니다.')

    def change_comment_color_green(self, size):
        if MyWindow.g_check:
            if self.green_bar.valueChanged:
                self.green_lcdNumber_2.setSegmentStyle(2)
                self.green_lcdNumber_2.display(size)
                MyWindow.g_green = size
        else:
            QMessageBox.information(self, 'Warning', '자막 설정을 하지 않았습니다.')

    def change_comment_color_blue(self, size):
        if MyWindow.g_check:
            if self.blue_bar.valueChanged:
                self.blue_lcdNumber_3.setSegmentStyle(2)
                self.blue_lcdNumber_3.display(size)
                MyWindow.g_blue = size
        else:
            QMessageBox.information(self, 'Warning', '자막 설정을 하지 않았습니다.')

    def _print(self):
        MyWindow.g_new_image = ""
        if MyWindow.g_open:
            filename = MyWindow.filename[0]
            image = cv2.imread(filename)

            new_img = image.copy()

            if MyWindow.g_gray == 1:
                MyWindow.g_gray = 0
                gray_img = cv2.cvtColor(new_img, cv2.COLOR_BGR2GRAY)
                MyWindow.g_new_image = gray_img
                cv2.imshow(filename, gray_img)
                cv2.waitKey()
            elif MyWindow.g_binary == 1:
                MyWindow.g_binary = 0
                gray_img = cv2.cvtColor(new_img, cv2.COLOR_BGR2GRAY)
                binary_img = gray_img.copy()
                binary_img[gray_img < 120] = 0
                binary_img[gray_img >= 120] = 255
                binary_img = cv2.cvtColor(binary_img, cv2.COLOR_GRAY2BGR)
                MyWindow.g_new_image = binary_img
                cv2.imshow(filename, binary_img)
                cv2.waitKey()
            elif MyWindow.g_rgb == 1:
                self._rgb_print(new_img, filename)
            else:
                QMessageBox.information(self, 'Warning', 'Color Space를 다시 선택하십시오.')
        else:
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')

    def _rgb_print(self, new_img, filename):
        size_list = list(new_img.shape)
        if MyWindow.g_check:
            if MyWindow.g_red == 255 and MyWindow.g_green == 255 and MyWindow.g_blue == 255:
                MyWindow.g_rgb = 0
                if MyWindow.g_comment != "":
                    new_img[-50:-15, :, :] = 0
                    if len(MyWindow.g_comment) <= size_list[1] / 10:
                        cv2.putText(new_img, text=MyWindow.g_comment, org=(5, size_list[0] - 30),
                                    fontFace=cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, fontScale=0.7,
                                    color=(255, 255, 255))
                    else:
                        QMessageBox.information(self, 'Warning', '내용이 너무 깁니다.')
                elif MyWindow.g_comment == "":
                    QMessageBox.information(self, 'Warning', '작성된 자막 내용이 없습니다.')
                MyWindow.g_new_image = new_img
                cv2.imshow(filename, new_img)
                cv2.waitKey()
            else:
                MyWindow.g_rgb = 0
                if MyWindow.g_comment != "":
                    new_img[-50:-15, :, :] = 255
                    if len(MyWindow.g_comment) <= size_list[1] / 10:
                        cv2.putText(new_img, text=MyWindow.g_comment, org=(5, size_list[0] - 30),
                                    fontFace=cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, fontScale=0.7,
                                    color=(MyWindow.g_blue, MyWindow.g_green, MyWindow.g_red))
                    else:
                        QMessageBox.information(self, 'Warning', '내용이 너무 깁니다.')
                elif MyWindow.g_comment == "":
                    QMessageBox.information(self, 'Warning', '작성된 자막 내용이 없습니다.')
                MyWindow.g_new_image = new_img
                cv2.imshow(filename, new_img)
                cv2.waitKey()
        elif MyWindow.g_check == 0:
            QMessageBox.information(self, '안내', '자막 설정이 안된 상태입니다.')
            MyWindow.g_rgb = 0
            MyWindow.g_new_image = new_img
            cv2.imshow(filename, new_img)
            cv2.waitKey()

    def _save(self):
        if MyWindow.g_open:
            if MyWindow.IMG_PATH != "":
                filename = os.path.join(MyWindow.IMG_PATH, f"save_{MyWindow.count}.jpg")
                cv2.imwrite(filename, MyWindow.g_new_image)
                QMessageBox.information(self, '안내', '파일이 저장되었습니다.')
                MyWindow.count += 1
                if self.file_position.text() == "":
                    MyWindow.IMG_PATH = ""
                else:
                    MyWindow.IMG_PATH = self.file_position.text()
            else:
                QMessageBox.information(self, 'Warning', '파일 저장 위치가 설정되지 않았습니다.')
        else:
            QMessageBox.information(self, 'Warning', '사진이 선택되지 않았습니다.')


def main():
    app = QApplication(sys.argv)
    editor = MyWindow()
    editor.show()
    app.exec_()


if __name__ == "__main__":
    main()
