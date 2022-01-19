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

print(lines) # 써져있는 그대로 출력

for line in lines :
    print(line, end='') # 보기 좋게 나옴
file.close()