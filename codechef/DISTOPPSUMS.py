t = int(input())

for _ in range(t):
    n = int(input())
    lst = [0] * n
    
    idx = 0
    for i in range(n, 0, -2):
        lst[idx] = i
        lst[n - idx - 1] = i - 1
        idx += 1
    
    print(' '.join(map(str, lst)))
    