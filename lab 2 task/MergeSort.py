def RandomArray(size):
    import random
    random_arr = []
    for a in range(size):
        random_arr.append(random.randint(0, size))
    return (random_arr)
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
def merge_sort(A,l,h):
    if l < h:
        mid = int((l+h)/2)
        merge_sort(A, l, mid)
        merge_sort(A, mid+1, h)
        merge(A, l, mid, h)
array = RandomArray(10000)
start = int(input("Enter Strating Index Of Sorted Arrray :"))
end = int(input("Enter Ending Index For Sorted Array :"))
import time
start_time = time.time()
sorted_array = merge_sort(array,start, end)
end_time = time.time()
run_time = end_time - start_time
print("Runtime of insertion sort is",run_time,"seconds")