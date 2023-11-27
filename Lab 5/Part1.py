def RandomArray(size):
    import random
    random_array = []
    for a in range (size):
        random_array.append(random.randint(-1, 100))       
    return (random_array)

def quick_sort(A,low,high):
    if low< high :
        q = partition(A, low, high)
        quick_sort(A, low, q-1)
        quick_sort(A, q+1, high)
        return A
        
        
def partition(A,l,h):
    pivot = A[l]
    i = l
    j = h
    while (i < j):
        
        while A[i] <= pivot and i < h:
            i += 1
        while A[j] > pivot:
            j -= 1
        if i < j:
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
    temp1 = A[l]
    A[l] = A[j]
    A[j] = temp1
    return j


A = RandomArray(100)
print(A)
quick_sort(A, 0, len(A)-1)
print(A)
        