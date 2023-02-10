# 2009.py
def  make_2D_array(m, n, value=0):
	mat = [[value for j in range(n)] for i in range(m)]
	return mat

A = make_2D_array(2, 3)
print(A)

B = make_2D_array(2, 4, 10)
print(B)
