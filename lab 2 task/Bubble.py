"""  Problem 5  """
#random array generated
def RandomArray(size):
    import random
    random_array = []
    for a in range (size):
        random_array.append(random.randint(-1, 20000))       
    return (random_array)

# Bubble sort
def BubbleSort(array,start, end):
    for i in range(start,end-1,+1): 
        for j in range(start,end):
            if array[j] > array[j+1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
    sorted_array = []
    for a in range(start,end,+1):
        sorted_array.append(array[a])
    return (sorted_array)

#Main Fuction
array = RandomArray(200000)
start = int(input("Enter Strating Index Of Sorted Arrray :"))
end = int(input("Enter Ending Index For Sorted Array :"))
import time
start_time = time.time()
sorted_bubble_array = BubbleSort(array,start,end)
end_time = time.time()
run_time = end_time - start_time
print("Runtime of insertion sort is",run_time,"seconds")
file = open("SortedBubbleSort.csv","w")
for a in range(len(sorted_bubble_array)):
    file.write(str(sorted_bubble_array[a])+"\n")
file.close()

