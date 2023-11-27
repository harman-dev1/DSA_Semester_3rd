def insertion_sort(arr):      
    for i in range(1,len(arr),+1):
        x = arr[i]
        j = i-1
        while arr[j] > x and j > -1:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = x
    return arr


def bucket_sort(arr):
    list_in_list = []
    num = 10
    
    for a in range(num):
        list_in_list.append([])
    
    for a in arr:
        integer_no = int(a * num)
        list_in_list[integer_no].append(a)
    
    for a in range(num):
        list_in_list[a] = insertion_sort(list_in_list[a])
    k = 0
    for i in range(num):
        for j in range(len(list_in_list[i])):
            print(i)
            arr[k] = list_in_list[i][j]
            k += 1
    return arr
    
    


x = [0.565, 0.656,0.897, 0.1234, 0.665, 0.3434]
print("Sorted Array is")
print(bucket_sort(x))
