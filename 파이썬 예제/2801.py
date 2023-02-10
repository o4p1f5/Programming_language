# 2801.py
f = open('data.txt', 'w') # 텍스트 파일 쓰기모드 개방
f.write('lee  80  90  95\n')
f.write('kim  85  70  75\n')
f.write('park 70  80  90\n')
f.close() # 파일 닫기

f = open('data.txt', 'r') # 텍스트 파일 읽기모드 개방
print(f.read())                  # 파일 전체 읽기
f.close()# 파일 닫기

import os     # os 모듈 가져오기
print(os.getcwd())   # 현재 작업 디렉토리
