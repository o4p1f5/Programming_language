# 2403.py
it = (x*x for x in range(5))
print(list(it))

it = (x*x for x in range(5) if x%2 == 0) # x가 짝수인 경우만
print(list(it))
