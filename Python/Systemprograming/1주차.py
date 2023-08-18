# # 1주차
# print
a = 'hello'
print("type:", type(a), "value:", a)
a = 1234
print("type:", type(a), "value:", a)
a = 4.213
print("type:", type(a), "value:", a)
a = True
print("type:", type(a), "value:", a)

print("#######################################################################")

# system 사용량
import sys
a = 112.34
b = 1233245467890
c = 123
print(type(a), sys.getsizeof(a))
print(type(b), sys.getsizeof(b))
print(type(c), sys.getsizeof(c))

print(a+b, a-b, a*b, a/b)

print("#######################################################################")

# c와 달리 정수끼리 계산이어도 최대한 정확한 값을 내려고 한다
# //을 사용하면 몫만 나오지만 계산한 수들의 자료형으로 표현된다
print(3/5, 3//5, 6.34//2.98)

print("#######################################################################")

# 13의 3승을 7진수로 표현
foo = 13**3
print(foo)
print(7**4, 7**3)

n3 = foo // 7**3
res = foo % 7**3
print(n3, res)
n2 = res // 7**2
res = res % 7**2
print(n2, res)
n1 = res // 7
n0 = res % 7
print(n1, n0)

# 7진수 13**3
print(n3, n2, n1)
# 13**3 확인
print(n3 * 7**3 + n2 * 7**2 + n1 * 7 + n0)

print("#######################################################################")

# if - elif - else
# {} 대신 : 사용
if 13**3 > 50**2:
    print("13**3 > 50**2")
elif 13**3 != 2197:
    print("13**3 != 2197")
else:
    print("else")

print("#######################################################################")

# 연습문제 1-2
x = 10
y = 11
if x == y:
    print("x is equal to y")
elif x > y:
    print("x is greater than y")
else:
    print("x is less than y")

print("#######################################################################")

# and, or
v = 10
if v % 2 == 0 and v < 12:
    print("v is even and less than 12")
elif v % 2 == 0 or v < 9:
    print("v is ~ ")

print("#######################################################################")

# is
# 같은 주소를 공유하는 같은 객체인지 확인
foo1 = [1, 2, 3]
bar = foo1
bar[1] = 10
print(foo1)

print(foo1 is bar)
goo = [1, 10, 3]
print(foo1 is goo)

foo2 = True
print(foo2 is True)

print("#######################################################################")

# 비교연산자를 연속으로 쓸 수 있음
foo3 = 15
if 10 < foo < 20:
    print("haha")

print("#######################################################################")

# 문자열을 쓸 때 "" 안에 ''를 사용하면 그냥 문자로 들어감
# 만약 "" 안에 ""를 문자로 사용하고 싶으면 \"\"로 사용하라
print("Life \"is\" too short")

print("#######################################################################")

# pick me 가사 쓰기
foo4 = "pick me" * 2 # 문자열에 곱하기를 할때 정수만 사용
print(foo4)

print(("pick up" * 3 + "up") * 2)
print("pick up" * 4)