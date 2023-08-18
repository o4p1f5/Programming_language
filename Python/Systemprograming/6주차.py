# print("#######################################################################")
# import sys
# from PyQt5.QtWidgets import QMainWindow, QApplication
# from PyQt5.QtCore import QCoreApplication
# from PyQt5 import uic
#
# class MyWindow(QMainWindow):
#     def __init__(self):
#         super().__init__()
#         # UI 불러오기
#         self.ui = uic.loadUi("untitled.ui", self)
#         self.btn_print.clicked.connect(self.hello_slot)
#         self.btn_reset.clicked.connect(self.slot_reset)
#         self.btn_close.clicked.connect(QCoreApplication.instance().quit)
#         self.count = 0
#         print("window geometry", self.geometry())
#         print("btn_print position", self.btn_print.pos())
#         print("btn_print size", self.btn_print.size())
#
#     def hello_slot(self):
#         self.count = self.count + 1
#         self.label_print.setText(f"Hello PyQt {self.count}")
#
#     def slot_reset(self):
#         self.count = 0
#         self.label_print.setText(f"Hello PyQt {self.count}")
#
# if __name__ == "__main__":
#     app = QApplication(sys.argv)
#     myWindow = MyWindow()
#     myWindow.show()
#     app.exec_()

print("#######################################################################")
import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic

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

def main():
    app = QApplication(sys.argv)
    editor = MyWindow()
    editor.show()
    app.exec_()

if __name__ == "__main__":
    main()