# 2주차
print("#######################################################################")

# 텍스트 부분 출력
text = "Life is too short, You need Python"
print(text[8], text[16])

print(text[0:4]) # 0 <= i < 4
print(text[:4]) # 0 <= i < 4
print(text[12:17])
print(text[28:34])
print(text[28:])
print(text[23:-7])

print("#######################################################################")
# 연습문제 1-4
new_text = text[-6:] + text[4:-6] + text[:4]
print(new_text)

print("#######################################################################")
# 변수 print
print("result:", text[:4], "output:", text[-6:])

print("#######################################################################")
# 포메팅
_class = "warrior"

# 기존 C 방식
print("class: %s, HP: %d, DPS: %f" % (_class, 100, 1456.23))
# format 사용
print("class: {}, HP: {}, DPS: {}".format(_class, 100, 1456.23))
# f라고 문자열 앞에 붙여주면서 포메팅해줌(python 3.6부터 사용가능)
print(f"class: {_class}, HP: {100}, DPS: {1459.23}")

print("#######################################################################")
# 문자열 함수
# c와 다르게 문자열에 함수가 있어서 객체에서 부르는것처럼 사용가능

# count
print("pick me pick me pick me up".count('pick me'))
text2 = "pick me pick me pick me up"
print(text2.count('pick me'))

# find
text3 = "For the python, of the python, by the python"
pyind = text3.find('py')
print("first", pyind)
pyind = text3.find('py', pyind+1) # 첫번째 py 이후 인덱스부터 찾기
print("second", pyind)

# index
pyind = text3.find('ruby')
print("ruby", pyind)
# find는 없는 문자열을 찾으면 에러가 아닌 -1 출력

# pyind = text3.index('ruby')
# print("ruby", pyind)
# index는 에러 발생
# Traceback (most recent call last):
#   File "C:\Users\오민진\Desktop\과제\시스템프로그래밍\1주차\main.py", line 194, in <module>
#     pyind = text3.index('ruby')
# ValueError: substring not found

# 예외처리 구문
try:
    pyind = text3.index("ruby")
    print("ruby", pyind)
except ValueError as ve: # 에러객체와 에러객체를 받을 변수
    print("value error:", ve)

print("#######################################################################")
# lower, upper
mixed = 'PYthon'
small = 'python'
print(f"{mixed}, {small}")
print(f"{mixed.lower()}, {small.upper()}")
print(mixed == small)
print(mixed.lower() == small.lower())

print("#######################################################################")
# strip, lstrip, rstrip
wise_saying = ' "Walking on water and developing software ' \
              'from a specification are easy if both are frozen..." '
print(wise_saying, "!")

# 문자열 앞뒤 공백만 지움
blank_removed = wise_saying.strip()
print(blank_removed)

# 문자열 앞뒤 ""만 지움
quote_removed = blank_removed.strip('"')
print(quote_removed)

# 문자열 오른쪽의 .만 지움
dot_removed = quote_removed.rstrip('.')
print(dot_removed)

# 위의 세 작업을 한번에 함
# 객체의 연속성
print(wise_saying.strip().strip('"').rstrip('.'))

print("#######################################################################")
# replace, split
Lincoln_said = "for the people, by the people, of the people"

# people을 python으로 변경
We_say = Lincoln_said.replace("people", "python")
print(We_say)

# 빈문자열로 변경해서 the를 제거
print(We_say.replace('the ', ''))

# 문자로 문자열 나누기
print(We_say.split(', '))

print("#######################################################################")
# 연습문제 1-5
marble = \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "그간 많은 stress 견뎌내며 비로소 대리암이 되었다네\n" \
    "모든 게 완벽했던 그 어느 날 난 너를 만나게 된 거야\n" \
    "모든 게 완벽했던 그 어느 날 난 너를 만나게 된 거야\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나를 보고 웃기라도 하는 날엔 하루 종일 아무것도 할 수 없네\n" \
    "그 눈으로 날 똑바로 바라보면 나는 녹아버릴 거야\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "이것이 염산반응이다\n" \
    "이것이 염산반응이다\n" \
    "Hcl이다 CaCO3다\n" \
    "2Hcl + CaCO3 -> CaCl2 +CO2 + H2O다.\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 염산과 반응하면 이산화탄소를 내며 녹는 대리암\n" \
    "나는 대리암 나는 대리암"

# 가사에서 “대리암”이 몇 번 나오는지, 5번째로 나오는 위치는 어디인지 찾아보세요.
Conut = marble.count('대리암')
print(Conut)

find1 = marble.find('대리암')
find2 = marble.find('대리암', find1+1)
find3 = marble.find('대리암', find2+1)
find4 = marble.find('대리암', find3+1)
find5 = marble.find('대리암', find4+1)
print(find5)

# 2번의 결과를 f문자열 포매팅으로 출력해보시오. 출력 예시: “대리암은 10번 나오고, 5번째로 나오는 위치는 30 이다.”
print(f"대리암은 {Conut}번 나오고, 5번째로 나오는 위치는 {find5}이다.")

# 가사에서 “대리암”을 “현무암”으로 바꿔보세오.
re_marble = marble.replace("대리암", "현무암")
print(re_marble)

print("#######################################################################")
# 컨테이너
# 기본 컨테이너로는 List, Dictionary, Tuple, Set 이 있다.

# list
list1 = []
list2 = list()

# 여러 자료형이 list 안에 들어갈 수 있음
basic_list = ["hello", 1.35, 456, False]
depth2_list = ["hello", 1.35, [456, False]]
depth3_list = [["hello"], [1.35, [456, False]]]

# 인덱싱 => 원소
print(basic_list[2])
# 슬라이싱 => 리스트
print(basic_list[1:3])
# 456 출력
print(depth2_list[2][0])
# false 출력
print(depth3_list[1][1][1])

# 없는 원소를 출력
try:
    print(depth3_list[5])
except IndexError as ie:
    print(ie)

# list 연산
mammal = ["dog", "cat", "human"]
reptile = ["snake", "lizard", "frog"]
bird = ["eagle", "sparrow", "chicken"]

# list 합치기
animal = mammal + reptile + bird
# 특정 list에 연산도 가능
# animal = mammal*2 + reptile + bird
print(animal)

# list 내장 함수
tottenham = ['Son', 'Alli', 'Bergwijn', 'Højbjerg', 'Tanganga', 'Skipp']

# sort(): 원소 알파벳순, 크기순 정렬, in-place 함수기 때문에 아무것도 리턴하지 않는다.
print("sort:", tottenham.sort())
print("sort:", tottenham)

# list는 find는 없어서 index로 찾아야함
print("Sonny index:", tottenham.index('Son'))

# 지우고 추가하기
# 1
tottenham.remove('Bergwijn')
tottenham.insert(1, 'Lo Celso')
print("inout", tottenham)

# 2
# pop(): 입력이 없으면 마지막 원소를 삭제하고 pop은 index의 원소를 삭제한다
tottenham.pop(-1)
# append(): 원소를 마지막에 추가한다. 두 리스트의 원소들을 합칠 때는 +나 extend()를 쓴다.
tottenham.append('Doherty')
print("inout", tottenham)

# del : 메모리에서 해당원소를 그냥 지워버린다
del tottenham[2]
# del tottenham[2:] => 2번 이후로 모두 삭제
# list 맨 뒤에 추가
tottenham += ['Romero', "Kane"]
print("inout", tottenham)

# list의 순서를 뒤집는다
tottenham.reverse()
print("reverse order", tottenham)

# len()
string = "hello"
print(len(string))
mylist =[1, 3, 4, 6]
print(len(mylist))

# list 수정
mylist[0] = 'Life'
print(mylist)
mylist[1:3] = ['is', 'too', 'short']
print(mylist)

# join()
path = "C:\\Users\\오민진\\Desktop\\과제\\시스템프로그래밍\\1주차\\venv\\Scripts\\python.exe"
dirs = path.split("\\")
print(path)
print(dirs)
dirs[0] = "D: "
print("\\".join(dirs))

time = ['10', '20', '54']
print(":".join(time))

# in
# list 안에 존재하는지 확인
twice = ["나연", "정연", "모모", "사나", "지효", "미나", "다현", "채영", "쯔위"]
if "채영" in twice:
    print("채영은 트와이스 입니다.")
    # index 함수를 사용할 때 발생할 에러를 방지하기 위해
    # 먼저 리스트에 있는 지 확인하고 찾기
    twice.index('채영')
if "채령" not in twice:
    print("채령은 트와이스가 아닙니다. 있지 입니다.")

print("#######################################################################")
# 연습문제 2-2
# top_lang_2009에서 원소를 삭제, 추가하여 top_lang_2019을 만들어 보세요.
top_lang_2009 = ["Java", "C", "Python", "C++", "C#"]
# => top_lang_2019 = ["C++", "PHP", "Java", "C", "Python"]

top_lang_2009 += ['PHP']
top_lang_2009.sort() # ['C', 'C#', 'C++', 'Java', 'PHP', 'Python']
del top_lang_2009[1:3] # ['C', 'Java', 'PHP', 'Python']
del top_lang_2009[-1] # ['C', 'Java', 'PHP']
top_lang_2009.append('C++') # ['C', 'Java', 'PHP', 'C++']
top_lang_2009.insert(0, 'Python') # ['Python', 'C', 'Java', 'PHP', 'C++']
top_lang_2009.reverse() # ['C++', 'PHP', 'Java', 'C', 'Python']

top_lang_2019 = top_lang_2009
print(top_lang_2019)

print("#######################################################################")
# 컨테이너
# 기본 컨테이너로는 List, Dictionary, Tuple, Set 이 있다.

# Dictionary
# key : value
pooh = {"species": "bear", "age": 5, "weight": 50}
tigger = {"species": "tiger", "age": 4, "weight": 40}
print("pooh's species is", pooh["species"])
print("pooh's weight is", pooh["weight"])
print("tigers's age is", tigger["age"])

pooh['age'] = 10
# 새로운 값 추가
pooh['height'] = 1.2
print(pooh)

del pooh['weight']
print(pooh)

pooh['color'] ='yellow'

# in 연산자는 value는 확인하지않고 오직 key가 있는지만 확인함
if 'color' in pooh:
    print("pooh's color", pooh['color'])

print("keys:", pooh.keys())
print("values:", pooh.values())
# key : value 값을 모두 보여줌
print("items:", pooh.items())

print("keys:", list(pooh.keys())[1])
print("values:", list(pooh.values())[2])
print("items:", list(pooh.items()))

print("#######################################################################")
# 연습문제 2-3
# 다음 코드를 dict를 이용하여 가독성을 높여보시오.
mulan = {"heroine" : "Crystal Liu", "director" : "Niki Caro", "release year" : 2020}
aladdin = {"heroine" : "Naomi Scott", "director" : "Guy Ritchie", "release year" : 2019}
beauty = {"heroine" : "Emma Watson", "director" : "Bill Condon", "release year" : 2017}

print("mulan's director is", mulan["director"])
print("aladdin's heroine is", aladdin["heroine"])
print("beauty and the beast's release year is", beauty["release year"])

print("#######################################################################")
# 컨테이너
# 기본 컨테이너로는 List, Dictionary, Tuple, Set 이 있다.

# Tuple
# list와 비슷하지만 변경은 불가능하다
# read only
basic_tuple1 = ("Hello", 1234, 1.234, True)
basic_tuple2 = "Hello", 1234, 1.234, True
print("tuple1", basic_tuple1[0])
print("tuple2", basic_tuple1[2:])
print("tuple3", basic_tuple2[1])

print("distribute values")
test = "pooh", "bear", 5, 50
name, species, age, weight = test
print("tupled pooh info:", name, species, age, weight)