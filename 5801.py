# 5801.py
def diff1(f, x): # 전방차분
    h = 0.001    
    return (f(x+h)-f(x))/h

def diff2(f, x): # 중심차분
    h = 0.001    
    return (f(x+h)-f(x-h))/(2*h)

