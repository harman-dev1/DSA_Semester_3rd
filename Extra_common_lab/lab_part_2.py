#iterative

#sum = 0
#for a in range(11):
    #sum += a
#print(sum)

#recursive.....
def sum(n):
    if n == 0:
        return 0
    else:
        return n + sum(n-1)
sum1 = sum(10)
print(sum1)