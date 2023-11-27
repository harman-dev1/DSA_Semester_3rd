def merge(A, low, mid, high):
    print(A)
    B = []
    i = low
    j = mid + 1
    while i <= mid and j <= high:
        if A[i] < A[j]:
            B.append(A[i])
            i += 1
        else:
            B.append(A[j])
            j += 1
    while i <= mid:
        B.append(A[i])
        i += 1
    while j <= high:
        B.append(A[j])
        j += 1
    for k in range(low, high + 1):
        A[k] = B[k-low]
def I_merge(A):
    p = 0
    i = 0
    for p in range(2,len(A)+1,p*2):
        for i in range(0,i+p,i+p):
            l = i
            h = i+p-1
            mid = int((l+h)/2)
            merge(A, l, mid, h)
    if p/2 < len(A):
       merge(A, 0, ((p/2)-1), len(A)-1)        
    print(A)   
            
            
    
    
    
    
    
    
    
sorted_arr = []
sorted_arr = I_merge([1,2,9,0,-1,-2])