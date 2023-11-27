"""#eg 1.1
a = 5
print("The value of a is :" ,a)
#eg 1.2
a = input("Enter Value of a :")
b = int(a)
print("Entered Value is :" + str(b))
#eg 1.4
array = [0 for a in range(0,10)]
print(array)
array_2d = [
    [0 for col in range(5)]for row in range(10)
]
print(array_2d)
#eg 1.5
import random
array = []
min = 0 
max = 20
n = 5
for a in range(n):
    num = random.randint(min,max)
    array.append(num)
print(array)
stri = ["U", "E", "T"]
for a in range(len(stri)):
    print(stri[a])
stri.reverse()
for a in range(len(stri)):
    print(stri[a])  

#1.7
arr = [1,3,4,5,6]
arr2 = arr[1:2]`
print(arr2)""

given_file = open (file = '.txt', mode = 'r')
lines = given_file. read ()
numbers = []
arr = lines.split()
for s in arr:
 num = int(s)
 numbers.append(num)
print(numbers)'''""

#1.9
arr = ["Hello","UET"]
file = open("say.txt","w")
for f in arr:
    file.write(f + "\n")""
    
#1.10
def dsisplay1(arr):
    for a in arr:
        print(a)
dsisplay1([1,2,3,4,5])"""

def get_name():
    arr = [1,2,3,4]
    return arr
arr = get_name()
print(arr)