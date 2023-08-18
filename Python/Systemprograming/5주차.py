# print("#######################################################################")
# numpy

# list vs numpy
# list는 배열이 모양이 이쁘지 않아도 되지만
# numpy는 정사각형 모양이어야 된다
# numpy는 배열처럼 계산이 된다

# pip install numpy
import numpy as np

# 기본 list
array1d = [1,2,3,4]
array2d = [[1,2], [3,4]]
array3d = [[[1,2], [3,4]], [[5,6], [7,8]]]

# numpy 배열로 만들기
array1d = np.array(array1d, dtype=np.int32)
array2d = np.array(array2d)
array3d = np.array(array3d)

# dtype = 자료형
# shape = 배열의 형태
# ndim = 차원 수
print(array1d.dtype, array1d.shape, array1d.ndim)
print(array2d.dtype, array2d.shape, array2d.ndim)
print(array3d.dtype, array3d.shape, array3d.ndim)

print("ones", np.ones((3,4)))
print("zeros", np.zeros((1,4)))
print("identity", np.identity(3))
print("eye", np.eye(2))

# 5개
print("Linespace", np.linspace(4,8,5))
# 0.6 간격으로
print("arange", np.arange(3,9,0.6))
# 범위의 정수를 랜덤하게 섞은 배열 생성
print("permutation", np.random.permutation(10))

val = np.arange(5, 10, 0.5)
ind = np.random.permutation(10)
print("mixed values", val[ind])

# 0,1 사이 난수
print("uniform sample\n", np.random.rand(2,5))
# 평군 0의 난수 (음수가 비교적 많음)
print("normal sample\n", np.random.randn(2,5))
# 0 ~ 4 사이 2차원 5개씩
print("integer sample\n", np.random.randint(0,4,(2,5)))

#reshape
foo = np.arange(0,6)
print("foo", foo)
# 1 X 6 -> 2 X 3
print(foo.reshape(2,3))
# print(foo.reshape(2,5))
# 원래 값으로 만들 수 없는 형태로는 바뀌지 않음
print(foo.reshape(2,3,1))
print(foo.reshape(3,2))
print(foo.reshape(3,2).shape)

data_list = [[[5, 6, 2], [3, 4, 9]],
             [[1, 7, 2], [3, 8, 0]]]
data = np.array(data_list)

# indexing
print("raw data\n", data)

print("indexing\n", data[0])

# slicing
print("indexing original\n", data[0, :, :])
print("list \n", data_list[0])

print("indexing original 2\n", data[0, 1, :])
print("list 2\n", data_list[0][1])

print("channel 1 data\n", data[:,:,1])
print("channel 1 data\n", data[:,:, 0:2])
print("channel 1,1 data\n", data[:,1,1])

# 연산
foo = np.array([[9, 3, 2], [1, 3, 9], [1, 6, 8]])
bar = np.array([[1, 4, 2], [3, 3, 4], [2, 1, 3]])

print("+", foo+bar)
print("**", foo**bar)
# 원소 곱셈
print("*", foo*bar)
print("*", np.multiply(foo,bar))
# 행렬 곱셈
print("@", foo@bar)
print("@", np.dot(foo,bar))

# 비교연산자
print(">", foo > bar)
# 결과물은 무조건 1차원
print("foo[foo>bar]", foo[foo>bar])
print("foo[foo>3]", foo[foo>3])
print("bar[bar>3]", bar[bar>3])
print(">", bar % 2 == 0)
print("foo[bar가 짝수인 인덱스의 수]", foo[bar % 2 == 0])

# 수학 함수
# precision = 소수점 길이, suppress = 소수점으로만 표현하도록
np.set_printoptions(precision=4, suppress=True)
foo = np.random.rand(5)
print(foo)

print("sin, cos", np.sin(foo), np.cos(foo))
print("sin^2 + cos^2", np.sin(foo)**2 + np.cos(foo)**2)
# exp = 2^foo
print("exp", np.exp(foo))
print("log", np.log(foo))
print("log(exp)", np.log(np.exp(foo)))
print("log(exp)", np.isclose(np.log(np.exp(foo))), foo)

np.set_printoptions(precision=4, suppress=True)
foo = np.random.rand(2,4)
print(foo)

print("mean over all", np.mean(foo))
print("mean over axis 0", np.mean(foo, axis=0))
print("mean over axis 1", np.mean(foo, axis=1))

print("sum",  np.sum(foo))
print("min",  np.min(foo, axis=0))
print("max",  np.max(foo, axis=1))
print("std",  np.std(foo, axis=1))

# 여러 배열 합치기
foo = np.array([[1, 2, 3], [4, 5, 6]])
bar = np.array([[11, 12, 13], [14, 15, 16]])

print("stack 0", np.stack([foo, bar], axis=0))
print("shape", np.stack([foo, bar], axis=0).shape)

print("stack 1", np.stack([foo, bar], axis=1))
print("shape", np.stack([foo, bar], axis=1).shape)

print("stack 2", np.stack([foo, bar], axis=2))
print("shape", np.stack([foo, bar], axis=2).shape)

print("concatenate 0", np.concatenate([foo, bar], axis=0))
print("shape", np.concatenate([foo, bar], axis=0).shape)

print("concatenate 1", np.concatenate([foo, bar], axis=1))
print("shape", np.concatenate([foo, bar], axis=1).shape)

foo = np.array([[1, 2, 3], [4, 5, 6]])
bar = np.array([[11, 12, 13], [14, 15, 16]])

for i, row in enumerate(foo):
    print("row", i, row)
    # row[1    2    3]
    # row[4    5    6]

    for j, elem in enumerate(row):
        print("elem", j, elem)
        # elem        1
        # elem        2
        # elem        3
        #
        # elem        4
        # elem        5
        # elem        6

print("#######################################################################")
# 연습문제
# 1. 임의의 3x4 배열 두 개를 만들고 np.concatenate로 합친 배열을 만드세요.
# 2. np.mean과 똑같이 작동하는 find_mean(array, axis=None) 함수를 구현하세요.
# 배열에 대해 for loop을 돌면서 주어진 axis에 대해 indexing 하여 평균으로
# 합칠 값들을 추출하고 평균을 계산하세요.

# foo = [[1,2,3],[4,5,6],[7,8,9]]
# bar = [[10,11,12],[13,14,15],[16,17,18]]
foo = np.random.rand(3,4)
bar = np.random.rand(3,4)

concat = np.concatenate([foo,bar])
print(concat)

def find_mean(array, axis=None):
    if axis is None:
        mean = np.sum(array) / array.size
    elif axis == 0:
        mean = []
        for col in range(array.shape[1]):
            slice = array[:, col]
            mean.append(np.sum(slice) / slice.size)
        mean = np.array(mean)
    elif axis == 1:
        mean = []
        for row_data in array:
            mean.append(np.sum(row_data) / row_data.size)
        mean = np.array(mean)
    else:
        assert False, "supperted axis are only 0, 1, None"

    return mean

print(foo)
print(find_mean(foo, axis=0))
print(find_mean(foo, axis=1))

print("#######################################################################")
# Qt : GUI를 만드는 라이브러리
# PyQt = PyQt5 : 파이썬에서도 사용하고자 파이썬 바인딩된 Qt
# import sys
# from PyQt5.QtWidgets import QApplication, QLabel
#
# app = QApplication(sys.argv)
# label = QLabel("Hello PyQt")
# label.show()
# app.exec_()

import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QCoreApplication

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setupUI()
        self.count = 0

    def setupUI(self):
        self.setWindowTitle("PyQt: putton event")
        self.setGeometry(500,200, 300, 150)
        print("window geometry", self.geometry())
        print("window geometry",
              self.geometry().x(), self.geometry().width())

        btn_print = QPushButton("Hello", self)
        btn_print.move(20, 20)
        btn_print.resize(100, 20)
        print("btn_print position, size", btn_print.pos(), btn_print.size())
        btn_print.clicked.connect(self.hello_slot)

        btn_reset = QPushButton("RESET", self)
        btn_reset.move(20, 50)
        btn_reset.resize(100, 20)
        print("btn_reset position, size", btn_reset.pos(), btn_reset.size())
        btn_reset.clicked.connect(self.slot_reset)

        btn_close = QPushButton("CLOSE", self)
        btn_close.move(20, 80)
        btn_close.resize(100, 20)
        print("btn_close position, size", btn_close.pos(), btn_close.size())
        btn_close.clicked.connect(QCoreApplication.instance().quit)

        self.label_print = QLabel("hello pyqt", self)
        self.label_print.move(150, 30)

    def hello_slot(self):
        self.count += 1
        self.label_print.setText(f"Hello pyqt {self.count}")

    def slot_reset(self):
        self.count = 0
        self.label_print.setText(f"Hello pyqt {self.count}")

def main():
    app = QApplication(sys.argv)
    my_wnd = MyWindow()
    my_wnd.show()
    app.exec_()

if __name__ == "__main__":
    main()










