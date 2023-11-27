""" .....Problem No 2.... """
#Generate Random Array
def RandomArray(size):
    import random
    random_arr = []
    for a in range(size):
        random_arr.append(random.randint(0, size))
    return (random_arr)

# Insertion Sort
def InsertionSort(array,start, end):
    for i in range(start+1,end,+1):
        j = i - 1
        x = array[i]
        while array[j] > x and j >= start:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = x
    sorted_array = []
    for a in range(start,end-1,+1):
        sorted_array.append(array[a])
    return sorted_array

#Main Function
arr = []
arr = RandomArray(10000)
start = int(input("Enter Starting Index(0 >=) :"))
end = int(input("Enter end Index(start index =<) :"))
import time
start_time = time.time()
sorted_array = InsertionSort(arr, start, end)
end_time = time.time()
run_time = end_time - start_time
print("Runtime of insertion sort is",run_time,"seconds")
    #Saving in File
file = open("SortedInsertionSort.csv","w")
for a in range(len(sorted_array)):   
    file.write(str(str(sorted_array[a])+"\n"))
file.close()