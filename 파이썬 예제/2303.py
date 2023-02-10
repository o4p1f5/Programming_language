# 2303.py
X = [1, 2, 3]
Y = ['a', 'b', 'c']
Z = zip(X, Y)
print(list(Z))
print(list(Z))

Z = zip(X, Y)
A, B = zip(*Z)
print(A)
print(B)
