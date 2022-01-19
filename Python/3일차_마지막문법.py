"""
# 연습문제 7-3
# 반환 값을 이용한 원 면적과 원주
def cir_area (radius) :
    area = radius * radius * 3.14
    return area

def cir_circum (radius) :
    circum = 2 * 3.14 * radius
    return circum

r = float(input('반지름을 입력하세요 :'))
a = cir_area(r)
b = cir_circum(r)

print('원의 면적 : %.2f, 원주의 길이 : %.2f' %(a,b)) 
"""

""" 
# 응용 - 반환 값을 이용한 사각형 면적 
def square (width, length) :
    area = width * length
    return area

def cubic (side) :
    area = side**2
    return area

w = float(input('직사각형의 가로를 입력하세요 :'))
l = float(input('직사각형의 세로를 입력하세요 :'))
s = float(input('정사각형의 한 변을 입력하세요 :'))
a = square(width = w,length = l)
b = cubic(side = s)

print('직사각형의 넓이 : %.2f, 정사각형의 넓이 : %.2f' %(a,b)) 
"""

""" 
# 소수 구하기
def isPrimeNumber(a):
    prime_yes = True
    for i in range(2,a) :
        if a % i == 0 :
            prime_yes = False
            break
    return prime_yes

is_prime = isPrimeNumber(2)
if is_prime :
    print('true')
else : 
    print('false') 
"""

""" 
# 영어단어맞추기
from operator import truediv
from unittest import result


def matchWord(in_word, answer) :
    if in_word == answer :
        return True
    else :
        return False

eng_dic  = {'apple' : '사과','lion' : '사자','book' : '책','love' : '사랑','friend' : '친구'}

for i in eng_dic :
    string = input(eng_dic[i] + "에 맞는 영어 단어는 ?")
    result = matchWord(string, i)
    if result :
        print("정답입니다!")
    else :
        print("틀렸습니다!")
"""

""" 
# 연습문제 7-4
# 세 수 중 가장 큰 수 찾기
def maxTwo (i, j) :
    if i > j :
        return i
    else :
        return j

def maxThree (a,b,c) :
    return maxTwo(a, maxTwo(b,c))

a = int(input('첫 번째 수를 입력하세요 :'))
b = int(input('두 번째 수를 입력하세요 :'))
c = int(input('세 번째 수를 입력하세요 :'))

result = maxThree(a,b,c)

print('%d, %d, %d 중 가장 큰 수 : %d' %(a,b,c,result))
"""

""" 
# 연습문제 7-5
# 최소 공배수 구하기
def compute(x,y) :
    if x > y :
        big = x
    else : 
        big = y

    while(True) :
        if((big % x == 0) and (big % y == 0)) :
            result = big
            break
        big = big + 1
    return result

a = int(input('첫 번째 수를 입력하세요: '))
b = int(input('두 번째 수를 입력하세요: '))

result = compute(x = a, y = b)
print('%d와 %d의 최소공배수 : %d' %(a,b,result)) 
"""

""" 
# 파일 쓰기
scores = ['안소영 97 80 93', '정예린 86 20 100', '김세린 91 88 99']
data = ''
for item in scores :
    data = data + item + '\n'

file = open('file1.txt', 'w')
file.write('안녕하세요. 반갑습니다. \n')
file.write(data)
file.close()

print('file1.txt 파일 쓰기 완료')

file = open('file1.txt', 'r')
lines = file.readlines()
file.close()

print(lines) # 써져있는 그대로 출력

for line in lines :
    print(line, end='') # 보기 좋게 나옴
 """

""" 
# 클래스 예제
class Animal :
    name = '고양이' # 멤버변수
    def sound(self) : # 멤버함수
        print("야옹")

cat = Animal() # 객체

print(cat.name)
cat.sound() 
"""

""" 
# 연습문제 8-1
# 클래스로 과일 이름/색상/맛 출력
class Fruit :
    name = '오렌지'
    color = '노란색'
    def taste(self) :
        print("새콤하다")
    def vitamin(self) :
        print('비타민 C가 풍부하다.')

orange = Fruit()

print("과일명 : %s" %orange.name)
print("과일 색깔 : %s" %orange.color)
orange.taste()
orange.vitamin() 
"""

""" 
# 연습문제 8-2
# 클래스 원의 면적과 원주
class Circle :
    radius = 10
    def getArea(self) :
        area = 3.141592 * self.radius * self.radius
        return area
    def getCircum(self) :
        circum = 2 * 3.141592 * self.radius
        return circum

cir = Circle() # 객체 생성

print('반지름 : %d' %cir.radius)
print('원의 면적 : %.2f' %cir.getArea())
print('원주의 길이 : %.2f' %cir.getCircum()) 
"""

""" 
# 생성자
class Person:
    def __init__(self, name):
        self.name = name
        print('%s님 반갑습니다' %name)
        

person1 = Person('활예린') 
"""

""" 
# 연습문제 8-3 
# 생성자 이용한 성적 합계 / 평균
class Student :
    total = 0
    avg = 0.0
    def __init__(self, name, kor, eng, math) :
        self.name = name
        self.kor = kor
        self.eng = eng
        self.math = math
    def getSum(self) :
        self.total = self.kor + self.eng + self.math
        return self.total
    def getAvg(self) :
        self.avg = self.getSum() / 3 
        return self.avg

s = Student(name = '홍지영', kor = 90, eng = 90, math = 100 )

print('이름 : %s' %s.name)
print('합계 : %d' %s.getSum())
print('평균 : %.1f' %s.getAvg())
"""

""" 
# math 모듈
import math

print('3.6의 소수점 절삭 : %.1f' %math.floor(3.6))
print('5.6의 무조건 올림 : %.1f' %math.ceil(5.1))
print('6.3의 반올림 : %.1f' %round(6.3))
print('6.6의 반올림 : %.1f' %round(6.6))

print('5의 펙토리알(1*2*3*4*5) : %d' %math.factorial(5))

print('sin(pi/4) : %.2f' % math.sin(math.pi / 4))
print('cos(pi) : %.2f' % math.cos(math.pi))
print('tan(pi/6) : %.2f' % math.tan(math.pi / 6))

print('5의 3승 : %d' % math.pow(5,3))
print('144의 제곱근 : %d' % math.sqrt(144))
print('log10(1000) : %.2f' % math.log10(1000)) 
"""

""" 
# random 모듈
# 주사위 게임
import random

again = 'y'
count = 1

while again == 'y' :
    print('-'*30)
    print('주사위 던지기 : %d번째' %count)
    me = random.randint(1,6)
    computer = random.randint(1,6)
    print('나 : %d' % me)
    print('컴퓨터 : %d' % computer)

    if me > computer :
        print('나의 승리!')
    elif me == computer :
        print('무승부!')
    else :
        print('컴퓨터의 승리!')

    count = count + 1
    again = input('계속하려면 y를 입력하세요!') 
"""

""" 
# Monte Carl experiment
import random

total = 10000
count = 0
i = 1

for i in range(total) :
    x = random.random()
    y = random.random()
    result = x**2 + y**2
    if result <= 1.0 :
        count = count + 1
        pass
    pass

print("랜덤으로 다트를 던졌을 때 \n반지름이 1인 원에 다트가 들어올 확률 : ",(count / total) * 4 ) 
"""

""" 
# 가위바위보 게임 - 응용
import random

def whoWin(me, com) :
    if me == '가위' :
        if com == '바위' :
            msg = '컴퓨터가 이겼습니다!'
        elif com == '가위' :
            msg = '비겼습니다!'
        else :
            msg = '당신이 이겼습니다!'
    elif me == '바위' :
        if com == '보' :
            msg = '컴퓨터가 이겼습니다!'
        elif com == '바위' :
            msg = '비겼습니다!'
        else :
            msg = '당신이 이겼습니다!'
    else :
        if com == '가위' :
            msg = '컴퓨터가 이겼습니다!'
        elif com == '보' :
            msg = '비겼습니다!'
        else :
            msg = '당신이 이겼습니다!'
    return msg

print('-'*50)
print('가위바위보 게임')
print('-'*50)

game = ['가위', '바위', '보']
again = '예'
check = '체크'

while again == '예' : 
    if again == '예' :
        check = '체크'
    while check == '체크' :
        me = input('당신 : ')
        if (me == '가위') or (me == '바위') or (me == '보') :
            check = '확인'
        else :
            print('다시 입력하십시오\n')
    com = random.choice(game)
    result = whoWin(me, com)

    print('컴퓨터 : %s' %com)
    print(result)

    again = input('다시 하시겠습니까? (다시 하려면 [예]를 입력하시오) : ')
    print('-'*50) 
"""

""" 
# datatime 예제
from datetime import datetime

today = datetime.now()
print(type(today))

print('%s년' % today.year)
print('%s월' % today.month)
print('%s일' % today.day)
print('%s시' % today.hour)
print('%s분' % today.minute)
print('%s초' % today.second)

today_str = today.strftime('%Y/%m/%d/ %H:%M:%S')
print(today_str) 
"""

""" 
# 이차방정식 판별식
import random

x = random.randint(1,100)
y = random.randint(1,100)
z = random.randint(1,100)

print('%dx^2 + %dx + %d = 0 \n위 이차방정식의 근의 계수는 ' %(x,y,z))
if y**2 - 4*x*z == 0 :
    print('두 개의 실근이다.')
elif y**2 - 4*x*z > 0 :
    print('중근이다.')
else :
    print('허근이다.') 
"""

# 이차방정식을 푸는 프로그램 답
import sys
import math

print('ax2 + bx + c = 0')

a = int(input('a값을 입력 '))
b = int(input('b값을 입력 '))
c = int(input('c값을 입력 '))

if a == 0 :
    print('a=0: 이차방정식이 아닙니다.')
    sys.exit() # 이차방정식이 아니면 프로그램 실행이 멈추는 매소드
    pass

D = b**2 - 4*a*c

if D > 0 : # 실근
    x1 = (-b + math.sqrt(D)) / (2*a)
    x2 = (-b - math.sqrt(D)) / (2*a)
    print(f"2개의 해 : x1 = {x1}, x2 = {x2}")
    pass
elif D == 0 : # 중근
    x = -b / (2*a)
    print(f"개의 해 : x = {x}")
    pass
elif D < 0 : # 허근
    print("해가 없습니다.")
    pass
else :
    print("잘못 입력했습니다.")
    pass 