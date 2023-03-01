import math
t = int(input())
primes = [2, 3, 5, 7]

for _ in range(t):
    x, y = map(int, input().split())
    
    factor: int
    for p in primes:
        if x % p == 0:
            factor = p
            break
    
    k = math.ceil((y - x - p) / 2)
    # res = [x, p] + [2] * k
    # print(res, sum(res))
    print(k + 1)
    
    

