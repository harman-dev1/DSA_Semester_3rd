from numpy import random 
def RandomArray(size):
    random_array = []
    for a in range (size):
        random_array.append(random.randint(-1, 100)) 
    return (random_array)
    
    
    
    
random_size_array = []
size = int(input("Enter size of random array :"))
random_size_array = RandomArray(size)
print(random_size_array)