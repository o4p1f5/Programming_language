# 2201.py
x = 1           # 전역변수
def func():
    x = 10      #  지역변수
    print("x = ", x)
    print("locals() = ", locals())
    # print("globals() = ", globals())

func()
##print(globals())
