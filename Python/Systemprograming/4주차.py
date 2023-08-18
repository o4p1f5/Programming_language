print("#######################################################################")
# 모듈 사용하기

# 기본 호출
# import list.ops

# 호출하면서 이름 바꾸기
# import list_ops as lo

# 특정한 것들을 가져와 사용하기(모듈 이름 안써줘도 됨) (안쓰는게 좋음)
# from list_ops import add, subtract, spam

# 파일 안에 있는 모듈 쓰기
import week4.list_ops as lo
import week4.dict_ops as do

foo = [1, 2, 3, 4, 5]
bar = [24, 52, 15, 24]
goo = lo.add(foo, bar)
print(f"{foo} + {bar} = {goo}")
# => [1, 2, 3, 4, 5] + [24, 52, 15, 24] = [25, 54, 18, 28]

goo = lo.multiply(lo.spam, lo.ham)
print(f"{lo.spam} * {lo.ham} = {goo}")
# => [51, 23] * [34, 67] = [1734, 1541]

weights = [65, 90, 42, 76]
heights = [1.65, 1.78, 1.59, 1.80]

w_names = ["RM", "Suga", "Jin", "V"]
h_names = ["Jimin", "RM", "Suga", "Jin"]
weights = dict(zip(w_names, weights))
heights = dict(zip(h_names, heights))
print("dict weights:", weights)
print("dict heights:", heights)
heights_sq = do.multiply(heights, heights)
bmi = do.divide(weights, heights_sq)
print("BMI:", bmi)
# => BMI: {'RM': 20.515086478979924, 'Suga': 35.59985760056959, 'Jin': 12.962962962962962}

print("#######################################################################")
# 연습문제 4-1
# str_util 이란 폴더를 만들고 그 안에 str_ops.py 를 만들어 다음과 같은 함수들을 구현하시오.
# 구현한 패키지를 활용하는 코드를 작성해보시오. 함수당 3가지 이상의 입력을 넣어 실행해 보시오.
import str_util.str_ops as sr
print(sr.find_all("hihihihihihihi", "hi"))

print(sr.count_all(text="Hello HELLO", keyword="Hello", insensitive=True))

print("#######################################################################")
# 클래스
class Dog:
    # 생성자 = 파이썬에서는 __init__이라는 이름으로 생성자가 정해져있음
    def __init__(self, name):  # self = class 자신의 객체라는 뜻
        self.name = name
        self.position = 0

    def __len__(self):
        return self.position

    def __str__(self):
        return f"My name is {self.name}"

    # 클래스 함수
    def bark(self):
        print(f"{self.name}: Wal! Wal!")

    def move(self, distance):
        self.position += distance
        print(f"{self.name} is at {self.position}")

    @staticmethod
    # self를 사용하지 않는 함수라면 @staticmethod로 선언해주기
    def eat():
        print("dog is eating")

# puppy = Dog("Dog")
# puppy.bark()
# puppy.move(10)
# print("puppy position :", puppy.position)

# Gae가 Dog 클래스 그 자체가 됨
Gae = Dog
puppy = Gae("Dog")
puppy.bark()
puppy.move(10)
print("puppy position :", puppy.position)

puppy.eat()

print(len(puppy))  # __len__
print(puppy)  # __str__

print("#######################################################################")
# 상속과 다형성
print("OOP: Object Oriented Programming")

class Animal:
    def __init__(self, name):
        self.name = name
    def introduce(self):
        print("my name is", self.name)
    def sound(self):
        print("...")

class Cow(Animal):  # 상속의 표시
    def __init__(self, name):
        #  부모클래스의 생성자를 그대로 가져다 씀
        # super().__init__(name)
        # 좀 더 정확하게 쓰려면 아래처럼 작성
        super(Cow, self).__init__(name)
    # Cow 클래스로 introduce를 사용하면 부모 클래스의 함수를 사용
    # 다른 방식으로 사용하고 싶다면 재정의 필요
    def sound(self):
        print("음메")

class Cat(Animal):
    def __init__(self, name):
        super().__init__(name)
    def sound(self):
        print("야옹")

cow = Cow("cow1")
cow.introduce()  # introduce
cow.sound()

animals = [Animal("ani"), Cow("cow2"), Cat("cat")]
for ani in animals:
    ani.introduce()
    ani.sound()

print("#######################################################################")
# 파이썬의 기본 패키지

# 다른 폴더에 있는 패키지 사용하기
import sys

# 겅로 추가
sys.path.append("C:/workspace/chio")

# 해당 패스의 package import
import week4.list_ops as lo
print(lo.spam)

# 파일이나 폴더 생성/삭제
import os
import shutil

dirpath= "C:/Users/오민진/OneDrive/바탕 화면/과제/시스템프로그래밍/newfolder"
os.mkdir(dirpath)  # 해당 경로에 파일 만들기
shutil.rmtree(dirpath)  # 해당 경로의 파일 지우기

# 파일 폴더 존재 확인
import os
import shutil

dirpath= "C:/Users/오민진/OneDrive/바탕 화면/과제/시스템프로그래밍/newfolder"

if os.path.isdir(dirpath):
    shutil.rmtree(dirpath)
else:
    print("there is no dir", dirpath)

mainpath = "C:/Users/오민진/OneDrive/바탕 화면/과제/시스템프로그래밍/main.py"

if os.path.isfile(mainpath):
    print("there is file", mainpath)

# 어떤 폴더에 들어있는 파일들의 목록 확인
import os
import shutil
import glob

search_pattern = "C:/Users/오민진/OneDrive/바탕 화면/과제/시스템프로그래밍/*"

result = glob.glob(search_pattern)
print(result)

print("#######################################################################")
# numpy

# list vs numpy
# list는 배열이 모양이 이쁘지 않아도 되지만
# numpy는 정사각형 모양이어야 된다
# numpy는 배열처럼 계산이 된다

# pip install numpy
import numpy as np

array1d = [1,2,3,4]
array2d = [[1,2], [3,4]]
array3d = [[[1,2], [3,4]], [[5,6], [7,8]]]

array1d = np.array(array1d, dtype=np.int32)
array2d = np.array(array2d)
array3d = np.array(array3d)

print(array1d.dtype, array1d.shape, array1d.ndim)
print(array2d.dtype, array2d.shape, array2d.ndim)
print(array3d.dtype, array3d.shape, array3d.ndim)