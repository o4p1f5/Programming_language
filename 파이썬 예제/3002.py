# 3002.py
class A:
    value = 10
    
x = A()
print(x.value)

import pickle
f1 = open('pickle.bin', 'wb')
pickle.dump(x, f1)
f1.close()

f2 = open('pickle.bin', 'rb')
y = pickle.load(f2)
print(y)
print(y.value)
f2.close()
