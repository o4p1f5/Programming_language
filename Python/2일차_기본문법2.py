'''
# 반복문
for x in range(5) :
    print('안녕하세요!')
    
print('=' * 11)

for _ in range(5) :
    print('안녕하세요!')

print('=' * 11)

for _ in '안녕하세요' :
    print('안녕하세요!')
'''

'''
# for문 예제
print("for문으로 1~10 정수 합계\n")
sum = 0
for i in range(1,11):
    sum = sum + i
    print('i의 값 : %2d => 합계: %d' %(i,sum))
'''

'''
# for문으로 문자열 처리하기
word = input('영어문장을 입력하세요 :')
for x in word :
    print(x) # 한글자씩 한 줄 띄어서 출력

print('=' * 11)

for x in word :
    print(x, end = '') # 한글자씩 옆으로 이어서 출력
'''

'''
# 섭씨/화씨 환산표 만들기
print('-' * 30)
print('%7s \t %7s' %('섭씨','화씨'))
print('-' * 30)

for c in range(-20, 31, 5) :
    f = c * 9.0 / 5.0 + 32.0
    print('%8d \t %8.1f' %(c,f))

print('-' * 30)
'''

'''
# 연습문제 4-1
# 4의 배수가 아닌 수
count = 0
for i in range(800,901) :
    if i % 4 !=0:
        print('%4d' %i,end = '')
        count = count + 1
    if count % 10 == 0 :
        print()
'''

'''
# 연습문제 4-2
# 길이 환산표 만들기
print('-' * 60)
print('%7s \t %7s \t %7s \t %7s' %('cm','mm','m','inch'))
print('-' * 60)

for cm in range(70,90,2) :
    mm = cm * 10.0
    m = cm * 0.01
    inch = cm * 0.3937
    print('%7d \t %7.0f \t %7.2f \t %7.1f'%(cm,mm,m,inch))
    
print('-' * 60)
'''

'''
# 이중 for문 - 전체 구구단 표
print('-' * 50)

for a in range(2,10) :
    for b in range(1,10) :
        c = a * b
        print('%d X %d = %d' %(a,b,c))
    print('-' * 50)
'''

'''
# while 문 예제
# 1 ~ 10 합계 구하기
print("for문으로 1~10 정수 합계\n")
sum = 0
i = 1

while i <= 10 :
    sum = sum + i
    print('i의 값 : %2d => 합계 : %d' %(i,sum))
    i = i + 1
'''

'''
# 연습문제 4-3
# while문 홀수 누적 합계
a = 200
count = 1
sum = 0
while count <= 300 :
    if(a % 2 == 1) :
        sum = sum + a
        print('%6d' % sum, end ='')
        if count % 10 == 0 :
            print()
        count = count + 1
    a = a + 1
'''

""" 
# 연습문제 5-1
"""

""" 
# 연습문제 5-2
scores = []
while True :
    x = int(input('성적을 입력하세요(종료 시 -1 입력): '))
    if x == -1:
        break
    else:
        scores.append(x)
sum = 0
for score in scores :
    sum = sum + score

avg = sum / len(scores)
print('합계 : %d, 평균 : %.2f' %(sum, avg)) 
"""