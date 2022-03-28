# 3001.py
import json
f1 = open('json.txt', 'w')
x= [1, 'simple', 'list']
json.dump(x, f1)
f1.close()

f2 = open('json.txt', 'r')
y = json.load(f2)
print(y)
f2.close()
