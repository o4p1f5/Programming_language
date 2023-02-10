# 1602.py
score = int(input('--->'))
if 90 <= score <= 100:  # 90 <= score  and score <= 100
    grade = 'A'   
elif 80 <= score:
    grade = 'B'    
elif 70 <= score:
    grade = 'C'   
elif 60 <= score:
    grade = 'D'
else:
    grade = 'F'
print("score = %d, grade = %s" % (score, grade))
