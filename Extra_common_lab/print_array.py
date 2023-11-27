#iterative
def show(arr):
    for a in ((arr)):
        print(a)
        
arr = [1,2,3,4,5,5]
(show(arr))

#Recursive
def print_arr(arr, start, end):
    if start == end:
        print(arr[start])
    else:
        print(arr[start])
        print_arr(arr, start+1, end)    
arr = [1,2,3,4,5]
start = 0
end =  4
print_arr(arr, start, end)