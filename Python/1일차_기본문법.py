'''
# 출력
'안녕하세요'
print('안녕하세요')
print("파이팅!")
print(f'값은 : {2/3: .2f}')

# 변수 및 연산자
a=123
type(a)
a = 10+20*30
print(a)

(10+20)*30

b= 10-20/10
print(b)

c = 17%5
print(c)

d = 29 % 6
print(d)

e = c % b
print(e)

a = 2**3 #제곱
print(a)

'''

'''
# 문자열 더하기
kor = '국어성적'
score = 80
string = kor + str(score)
print(string)
'''

'''
# 문자열 뽑아쓰기
date = '20191025'
print(date)
year = date[0:4]
month = date[4:6]
day = date[6:]
date2 = year + month + day
print(date2)
'''

'''
# 형변환
color = '빨강'
s = str(f'나는 {color}을 좋아해') # 최근 사용 방식
print(s)
s2 = '나는 %s을 좋아해' %color # 다른 방식
print(s2)
'''

'''
# 평균 내기 예제
kor = 88
eng = 95
math = 97
sum = kor + eng + math
avg = sum / 3.0
print(f'합계 : {sum}, 평균 :{avg : .2f}')
'''

'''
# 출력 유형
person = input('이름을 입력하세요: ')
print(f"{person}님 안녕하세요.")
'''

'''
# if - else 조건문
age = input('나이를 입력하세요: ')
chenk = input('생일이 지나셨습니까? (y/n)')
if chenk == 'n':
    print(f"{person}님의 만 나이가 {int(age) - 2} 살로 확인되었습니다.")
    # 중괄호 {}가 없기 때문에 Tab키를 구분
else :
    print(f"{person}님의 만 나이가 {int(age) - 1} 살로 확인되었습니다.")
'''

'''
# if - else 조건문
x = int(input('숫자를 입력하세요 : '))
if x > 0:
    print("양수입니다")
else :
    print("음수입니다")
'''

'''
# if 조건문
num = int(input('하나의 수를 입력하세요 :'))
result = '3의 배수도 5의 배수도 아니다.'

if num%3 == 0:
    result = '3의 배수이다.'
if num%5 == 0:
    result = '5의 배수이다.'

if num%3 == 0 and num%5==0 :
    result = '3의 배수이면서 5의 배수이다.'

print('%d => %s' %(num,result))
'''

'''
# if - elif - else 조건문
score = int(input('점수를 입력해 주세요. :'))
if score >= 90 :
    grade = 'A'
elif score >= 80 :
    grade = 'B'
elif score >= 70 :
    grade = 'C'
elif score >= 60 :
    grade = 'D'
else :
    grade = 'F'

print('성적 :', score)
print('등급 :', grade)
'''

'''
# 계산기 만들기
print('계산 항목 => 기능 선택')
print('1.더하기')
print('2.빼기')
print('3.곱하기')
print('4.나누기')

s = input('계산기 기능을 선택하세요(1/2/3/4) :')
if not s==1 or not s==2 or not s==3 or not s==4 :
    print(f'올바른 입력이 아닙니다.')
    exit() 
    
a = int(input('첫 번째 숫자를 입력하세요 :'))
b = int(input('두 번째 숫자를 입력하세요 :'))

if s == '1' :
    print(f'{a} + {b} = {a+b}')
elif s == '2' :
    print(f'{a} - {b} = {a-b}')
elif s == '3' :
    print(f'{a} * {b} = {a*b}')
elif s == '4' :
    print(f'{a} / {b} = {a/b}')
'''

'''
# 연습문제 3-2
char = input('영어 소문자 하나를 입력하세요:')
if(char == 'a' or char == 'e' or char == 'i' or char == 'o' or char == 'u'):
    print('%s-> 모음'%char)
else:
    print('%s-> 자음'%char)
'''

'''
# 연습문제 3-3
height = int(input('키를 입력해 주세요: '))
weight = int(input('몸무게를 입력해 주세요 :'))
s = (height - 100) * 0.9;
print('=' * 50)
print('키 :',height)
print('몸무게 :',weight)

if weight > s :
    print('딱 보기 좋습니다. 경우에 따라 다이어트가 필요합니다!')
else :
    print('표준 또는 마른 체형입니다!')

print('=' * 50)
'''

'''
# 연습문제 3-4
month = int(input('월을 입력해주세요 :'))
if month >= 3 and month <= 5 :
    season = '봄'
    print(month,'월은 ',season,'입니다')
elif month >= 6 and month <= 8 :
    season = '여름'
    print(month,'월은 ',season,'입니다')
elif month >= 9 and month <= 11 :
    season = '가을'
    print(month,'월은 ',season,'입니다')
else :
    season = '겨울'
    print(month,'월은 ',season,'입니다')
'''

# 연습문제 3-5
buy = int(input('물건 구매가를 입력하세요: '))
if buy >= 10000 and buy < 50000:
    rate = 5.0
elif buy >= 50000 and buy < 300000:
    rate = 7.5
elif buy >= 300000:
    rate = 10.0
else :
    rate = 0

print('구매가 :', buy)

halinpay = buy * (rate / 100)

print(f'할인율 : {rate}%')
print('할인 금액 : %.f' %halinpay)
print('지불 금액 : %.f' %(buy-halinpay))
