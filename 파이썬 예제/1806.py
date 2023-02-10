# 1806.py
print("----------- for in a set ----------")
for a in {1, 2, 3}:
    print("a = ", a)

print(" -----------for in a dict ")
D = {'one':1,'two':2,'three':3}  
for key in D:  # for key in D.keys():
    print("key = ", key)

for value in D.values():
    print("value = ", value)

for item in D.items():  # type(item) == tuple
    print("item = ", item)

for key, value in D.items():
    print("key ={0} : value ={1}".format(key, value)) 
