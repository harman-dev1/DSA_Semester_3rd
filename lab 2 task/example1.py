def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)
    


import time
start_time = time.time()
n = 1500
ans = (factorial(n))
print(ans)
end_time = time.time()
run_time = (end_time - start_time)
print("Run TIme = " , run_time)