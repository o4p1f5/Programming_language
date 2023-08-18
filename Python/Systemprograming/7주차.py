print("#######################################################################")
import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5.QtGui import QColor, QFont

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = uic.loadUi("textEditor.ui", self)
        self.setup_ui()

    def setup_ui(self):
        # self.[객체이름].triggered.connect(self.[함수이름]])
        self.actionOpen.triggered.connect(self.open_file)
        self.actionSave.triggered.connect(self.save_file)

        self.textEdit.cursorPositionChanged.connect(self.update_status)

        self.comboBox.addItems(["굴림", "돋움", "바탕"])
        self.textEdit.setFontFamily(self.comboBox.currentText())
        self.comboBox.currentIndexChanged.connect(self.change_font)

        # # 개별적으로 동작하게 설정하는 방식
        # self.radioButton_black.pressed.connect(self.set_color_black)

        # button group을 이용해 그룹 단위로 동작 실행
        self.rb_color_group = QButtonGroup()
        self.rb_color_group.addButton(self.radioButton_black)
        self.rb_color_group.addButton(self.radioButton_red)
        self.rb_color_group.addButton(self.radioButton_blue)
        self.rb_color_group.buttonPressed.connect(self.change_color)

        # bold, italic
        self.checkBox_bold.toggled.connect(self.set_bold)
        self.checkBox_italic.toggled.connect(self.set_italic)

        # slider
        self.horizontalSlider.setMinimum(10)
        self.horizontalSlider.setMaximum(20)
        self.horizontalSlider.valueChanged.connect(self.change_font_size)

        # 문자열 replace
        self.pushButton_replace.clicked.connect(self.replace)


    def open_file(self):
        filename = QFileDialog.getOpenFileName(filter="Text files (*.txt)")
        filename = filename[0]
        print("open file:", filename)
        if not filename:
            return

        # with = 컨텍스트 매니저 = 자동으로 close
        # "r" = read
        with open(filename, "r", encoding="utf8") as f:
            text = f.read(10000)
            self.textEdit.setText(text)

    def save_file(self):
        filename = QFileDialog.getSaveFileName(filter="Text files (*.txt)")
        filename = filename[0]
        print("open file:", filename)
        if not filename:
            return

        # "w" = write
        with open(filename, "w", encoding="utf8") as f:
            f.write(self.textEdit.toPlainText())
            print("open file:", self.textEdit.toPlainText())

    def update_status(self):
        text_len = len(self.textEdit.toPlainText())
        cursor_pos = self.textEdit.textCursor().position()
        cursor_anc = self.textEdit.textCursor().anchor()
        if cursor_pos == cursor_anc:
            status = f"text length:{text_len}, cursor position: {cursor_pos}"
        else:
            status = f"text length:{text_len}, cursor range: {cursor_anc}~{cursor_pos}"
        self.statusbar.showMessage(status)

    def change_font(self, cur_index):
        print("comboBox index:", cur_index)
        self.textEdit.setFontFamily(self.comboBox.currentText())

    # black button 하나만 작동
    # def set_color_black(self):
    #     print("black color selected")

    def change_color(self, rbutton):
        print("change color to", rbutton.text())
        if rbutton is self.radioButton_black:
            self.textEdit.setTextColor(QColor(0, 0, 0))
        elif rbutton is self.radioButton_red:
            self.textEdit.setTextColor(QColor(255, 0, 0))
        elif rbutton is self.radioButton_blue:
            self.textEdit.setTextColor(QColor(0, 0, 255))
        else:
            raise ValueError("error : " + rbutton.text())

    def set_bold(self, checked):
        print("set bold:", checked)
        if checked:
            self.textEdit.setFontWeight(QFont.Bold)
        else:
            self.textEdit.setFontWeight(QFont.Normal)

    def set_italic(self, checked):
        checked = self.checkBox_italic.checked()
        self.textEdit.setFontItalic(checked)

    def change_font_size(self, size):
        print("font size:", size)
        self.label_slider_value.setText(f"Font size: {size}")
        self.textEdit.setFontPointSize(size)

    # lineEdit_replace_src의 단어를 lineEdit_replace_dst의 단어로 변경
    def replace(self):
        text = self.textEdit.toPlainText()
        text = text.replace(self.lineEdit_replace_src.text(), self.lineEdit_replace_dst.text())
        self.textEdit.setText(text)

def main():
    app = QApplication(sys.argv)
    editor = MyWindow()
    editor.show()
    app.exec_()

if __name__ == "__main__":
    main()

# print("#######################################################################")
# import cv2
#
# image = cv2.imread("C:\Systemprograming\cat.jpg")
# cv2.imshow("cat", image)
# key = cv2.waitKey()
# print("key in:", key)
# cv2.destroyAllWindows()