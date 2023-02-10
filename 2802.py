# 2802.py
f = open('data.txt', 'r')
for line in f:  # for line in f.readlines():
	print(line, end='')
f.close()

f = open('data.txt', 'r')
print(f.readlines())
f.close()
