# 5901.py
def Integrate1(f, a, b, n=100): # 사각형 면적의 합
    h=(b-a)/n    
    area = 0  
    for k in range(n):
        x = a + k*h
        area += f(x)*h        
    return area

def Integrate2(f, a, b, n=100): # 사다리꼴 공식
    h=(b-a)/n
    area = 0 
    for k in range(1, n):
        x = a + k*h        
        area += f(x)
    area *= 2
    area += f(a) + f(b)
    area = (area*h)/2    
    return area

print(Integrate1(lambda x: x**2, 0, 10))
print(Integrate1(lambda x: x**2, 0, 10, 1000))
print(Integrate2(lambda x: x**2, 0, 10))
print(Integrate2(lambda x: x**2, 0, 10, 1000))
