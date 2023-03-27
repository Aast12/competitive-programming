import math
import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n - r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

def fact(n, mod):
    if n == 0:
        return 1

    f = 1
    for i in range(1, n + 1):
        f *= i
        f %= mod

    return f

n = int(input())
a = map(int, input().split())

MOD = 998244353
MAX = int(1000000)
sieve = [True] * MAX
sieve[1] = False
primes = []

for i in range(2, int(math.sqrt(MAX)) + 1):
    if sieve[i]:
        j = i * i
        while j < MAX:
            sieve[j] = False
            j += i

# for i in range(2, MAX):
#     if sieve[i]:
#         primes.append(i)


primes = set(filter(lambda x : sieve[x], a))

prime_combinations = ncr(len(primes), n) % MOD
exp_permutatioins = fact(n, MOD) 

print(prime_combinations * exp_permutatioins % MOD)