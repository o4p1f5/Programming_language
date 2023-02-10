# 2901.py
f = open('test.bin', 'wb') # 이진 쓰기모드 개방
f.write(b'0123456789abc')
f.close()

f = open('test.bin', 'rb') # 이진 읽기모드 개방
print(f.read()) # 프로그래밍 모드에서는 print로 출력해야함
f.close()
