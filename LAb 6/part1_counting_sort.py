# count Sort
def count_Sort(A):
    min_element = min(A)
    for a in range(len(A)):
        A[a] = A[a] - min_element
        
    max_element = max(A)
    c_arr = [0] * (max_element+1)
    
    for a in range(len(A)):
        c_arr[A[a]] += 1
    
    i = 0
    j = 0
    while i < len(c_arr):
        if c_arr[i] > 0:
            A[j] = i
            j += 1
            c_arr[i] -= 1
        else:
            i += 1
    
    for a in range(len(A)):
        A[a] = A[a] + min_element
       
    
        
    
    
           
# Main Driver Code        
A = [-5, -30, 0, -3, 8, 5, -1, 10]
count_Sort(A) 
print(A)