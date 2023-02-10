# ex1804.py
nAlphabet = nHanGul = nOthers = 0
for s in "Python?파이썬!":
    #print(s)
    if ord('A') <= ord(s) <= ord('Z') or ord('a') <= ord(s) <= ord('z'):
        print('Alphabet = ', s)
        nAlphabet += 1                
    elif ord('가') <= ord(s) <= ord('힣'):
        print('HanGul = ', s)
        nHanGul += 1
    else:
        print('Others = ', s)
        nOthers += 1
        
print("\nnAlphabet = %d" % nAlphabet)
print("nHanGul   = %d" % nHanGul)
print("nOthers   = %d" % nOthers)
