""" .....Problem No 6.... """
#Generate Random Array
def RandomArray(size):
    import random
    random_arr = []
    for a in range(size):
        random_arr.append(random.randint(0, size))
    return (random_arr)

#SelectionSort
def SelectionSort(array,start, end):
    for i in range(start , end -1, +1):
        k = i
        for j in range(i,end,+1):
            if array[k] > array[j]:
                k = j
        temp = array[i]
        array[i] = array[k]
        array[k] = temp
    sorted_arr = []
    for a in range(start,end,+1):
        sorted_arr.append(array[a])
    return sorted_arr
#Main Function
array = RandomArray(10000)
start = int(input("Enter Strating Index Of Sorted Arrray :"))
end = int(input("Enter Ending Index For Sorted Array :"))
import time
start_time = time.time()
sorted_array = SelectionSort(array,start, end)
end_time = time.time()
run_time = end_time - start_time
print("Runtime of insertion sort is",run_time,"seconds")
file = open("SortedSelectionSort.csv","w")
for a in range(len(sorted_array)):
    file.write(str(sorted_array[a])+"\n")
file.close()

