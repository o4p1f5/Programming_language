# 3주차

# 파이썬은 들여쓰기로 구문이 구분되는데, 들여쓰기 전엔 꼭 :을 쓴다

print("#######################################################################")
# 조건문, 반복문
mylist = [1, 2, 3, 4]

for i in mylist:
    print(i)

marvel_heroes = ["iron man", "thor", "hulk", "spider man", "black widow", "capt. america", "capt. marvel"]
dc_heroes = ["batman", "superman", "aquaman", "wonder woman", "harley quinn"]

myhero = 'iron man'
if myhero in marvel_heroes:
    print(f"{myhero}: my hero is ironman in marvel heros")
elif myhero in dc_heroes:
    print(f"{myhero}: my hero is ironman, but ironman is not dc hero")
else:
    print(f"{myhero}: We are villains!")

for i in range(len(dc_heroes)):
    print(i, dc_heroes[i])

for hero in dc_heroes:
    print(hero)

i = 0
while i < len(dc_heroes) and dc_heroes[i].endswith('man'):
    print(dc_heroes[i])
    i += 1

for hero in marvel_heroes:
    if hero.startswith('spider'):
        print("continue")
        continue
    if hero.startswith("capt"):
        print('break')
        break
    print(hero)

print("#######################################################################")
# 연습문제 3-1
# for 반복문을 이용하여 2의 배수도 아니고 3의 배수도 아닌 5번째 숫자를 찾으시오.
count = 0
value = 0
for i in range(100):
    if i%3 != 0 and i%2 != 0:
        count += 1
    if count == 5:
        value = i
        break
print(value)

# 또다른 해설
# count = 0
# for i in range(100):
#     if i % 2 == 0 or i % 3 == 0:
#         continue
#     else:
#         count += 1
#         if count == 5:
#             print(f"find 5th number {i}")

print("#######################################################################")
# enumerate는 for문에서 리스트를 반복할 시 인덱스도 받을 수 있는 반복 객체를 만들어 준다.
# zip은 두 개의 리스트를 묶어서 각 리스트의 원소가 하나씩 합쳐진 튜플의 반복 객체를 만들어준다.
print(list(enumerate(marvel_heroes)))

print(list(zip(marvel_heroes, dc_heroes)))

for i, hero in enumerate(marvel_heroes):
    if i%2 == 0:
        print(i, hero)
        # print(1, hero, dc_heroes[i])

for mv, dc in zip(marvel_heroes, dc_heroes):
    print(f"{mv} vs {dc}")

print("#######################################################################")
# 연습문제 3-2
# enumerate와 zip을 동시에 써서 위에서 선언한 marvel_heroes, dc_heroes 변수로부터 다음과 같은 내용을 출력하는 코드를 작성하시오.

# 이중 튜플
print(list(enumerate(zip(marvel_heroes, dc_heroes))))

for i, (mv, dc) in enumerate(zip(marvel_heroes, dc_heroes)):
    print(f"Round {i}. {mv} vs {dc}")

print("#######################################################################")
# 딕셔너리 반복
hero_names = {"iron man": "로다주", "thor": "햄식이"}

# key만
for key in hero_names:
    print(key, hero_names[key])

# value만
for name in hero_names.values():
    print(name)

# item
for key, value in hero_names.items():
    print(key, value)

# index까지
print(list(enumerate(hero_names.items())))
for i, (key, value) in enumerate(hero_names.items()):
    print(i, key, value)

# 기존 리스트에 변화는 준 새로운 리스트 만들기 _ 1
super_heros = []
for hero in marvel_heroes:
    super_heros.append(hero + '_super')
print("super heroes", super_heros)

# 기존 리스트에 변화는 준 새로운 리스트 만들기 _ 2
super_heros = [hero + '_super' for hero in marvel_heroes]
print("super heroes", super_heros)

# 기존 리스트에 변화는 준 새로운 리스트 만들기 _ 3
man_heroes = [hero for hero in marvel_heroes if hero.endswith('man')]
print("man heroes", man_heroes)

# 두 list 묶어서 하나의 딕셔너리로 만들기
print("dictionary comprehension")
abilities = ["suit", "Mjölnir", "physical power", "spider web"]
heroes = {name: power for name, power in zip(marvel_heroes, abilities)}
print("hero's ability:", heroes)

print("#######################################################################")
# 연습문제 3-3. Iterate over Dict
# 다음 dict에 들어있는 값(숫자)들을 제곱한 새로운 dict를 만들어보시오.
stddev = {"foo": 1.5, "bar": 2.4, "goo": 5.2}
variance = {name: (values**2) for name, values in stddev.items()}
print(variance)

# stddev = {"foo": 1.5, "bar": 2.4, "goo": 5.2}
# new_dic = {}
# for key, val in stddev.items():
#     new_val = val ** 2
#     new_dic[key] = new_val
# print(new_dic)

print("#######################################################################")
# 연습문제 3-4. List Comprehension
# List comprehension을 이용하여 marvel_heroes에서 홀수번째 영웅만 추출한 리스트를 만들어보시오. (Hint: enumerate)
new_marvel = [hero for i, hero in enumerate(marvel_heroes)
              if i % 2 == 0]
print(new_marvel)

print("#######################################################################")
# 함수
# 예 1
def add(n1, n2):
    return n1 + n2

print(add(1, 2))

# 예 2
def average_list(data, start, end, skip, verbose):
    if end: # end가 none가 아니면
        data = data[:end]
    if start:
        data = data[start:]
    if skip:
        for val in skip:
            if val in data:
                data.remove(val)
    sumval = 0
    for d in data:
        sumval += d
    average = sumval / len(data)

    if verbose:
        print(f"average over indices [{start}~{end}) with skipping values {skip} = {average}")
    return average

data = [1, 2, 3, 4, 5, 6, 7, 8, 9]

# 이렇게 입력인자가 많으면 자료형이나 어떤 의미를 가졌는지를 헷갈릴 수 있음
# 키위드 인자를 사용한다
avg = average_list(data, 2, 7, [4], True)

# def average_list(data,start,end,skip,verbose):
#     if start:
#         data = data[start:]
#     if end:
#         data = data[:end]
#     if skip:
#         if skip in data:
#             for s in skip:
#                 data.remove(s)
#     sum = 0
#     for i in data:
#         sum += i
#     average = sum / len(data)
#
#     if verbose:
#         print(f"리스트의 평균값은 {average}입니다.")
#
# data = [1,2,3,4,5,6,7,8,9]
# average_list(data,0,6,[1],True)


avg = average_list(data=data, start=2, end=7, skip=[4], verbose=True)

# 함수 인자의 기본값은 C언어처럼 지정하면 됨
def average_list_with_default(data, start=None, end=None, skip=None, verbose=False):
    return average_list(data, start, end, skip, verbose)

print(average_list_with_default(data))

print("#######################################################################")
### 연습문제 3-5. add_lists()
#두 개의 숫자 리스트를 입력인자로 받아 원소별로 합산한 리스트를 출력하는 함수를 구현하시오. 함수는 다음과 같은 입력인자를 가져야 한다. 함수 구현 후 5가지 이상의 다른 입력인자를 넣어 실행해보시오.
def list_sum(list1, list2, shortlen, start=0, verbose=True):
    foo = list1[start:]
    bar = list2[start:]
    if shortlen is False:
        maxlen= max(len(foo), len(bar))
        foo += [0] * (maxlen - len(foo))
        bar += [0] * (maxlen - len(bar))

    result = [f + b for f, b in zip(foo, bar)]
    print(f"{foo}+{bar}={result}")

    if verbose:
        return result

foo = [1,2,3,4]
bar = [1,2,3,4,5]

print(list_sum(list1=foo, list2=bar, start=0, shortlen=False, verbose=True))

# def add_list(list1, list2, shortlen = True, start = 0, verbose = False):
#     if start:
#         list1 = list1[start:]
#         list2 = list2[start:]
#
#     if shortlen:
#         new_list = [l1 + l2 for l1, l2 in zip(list1, list2)]
#     else:
#         if len(list1) > len(list2):
#             new_list = list1
#             for i in range(len(list2)):
#                 new_list[i] = list1[i] + list2[i]
#         else:
#             new_list = list2
#             for i in range(len(list1)):
#                 new_list[i] = list1[i] + list2[i]
#     if verbose:
#         print(new_list)
#
# list1 = [1,2,3,4,5,6,7]
# list2 = [1,2,3]
#
# add_list(list1, list2, False, 0, True)

print("#######################################################################")
