# 5702.py
# ref: Foundamentals of Data Structure in C, Horowitz, Sahni et. al.
def permute1(n, size, A):
    if n == size:
        print(A[0:size+1])
        
    for i in range(n, size+1):
        A[i], A[n] = A[n], A[i] # swap(A[i], A[n])
        permute1(n+1, size, A)
        A[i], A[n] = A[n], A[i] # swap(A[i], A[n])

# ref: https://en.wikipedia.org/wiki/Heap%27s_algorithm
def permute2(n, A):
    if n == 1:
        print(A)
    else:
        for i in range(n-1):
            permute2(n-1, A)
            if n%2 == 0:
                A[i], A[n-1] = A[n-1], A[i] # swap(A[i], A[n-1])
            else:
                A[0], A[n-1] = A[n-1], A[0] # swap(A[0], A[n-1])
        permute2(n-1, A)
    

A = [1, 2, 3, 4]
permute1(0, len(A)-1, A)

A = [1, 2, 3]
permute2(len(A), A)

