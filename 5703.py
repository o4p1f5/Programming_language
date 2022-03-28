# 5703.py
import itertools

A = [1,2,3]
print(list(itertools.permutations(A)))
for p in itertools.permutations(A):
	print(p)
	
print(list(itertools.permutations(A, 2)))

print(list(itertools.combinations(A, 3)))
print(list(itertools.combinations_with_replacement('ABC', 2)))

