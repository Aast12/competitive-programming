t = int(input())

for _ in range(t):
    n, x = [int(i) for i in input().split()]

    max_v, min_v = n + 1, 1 - n
    if x > max_v or x < min_v:
        print(-1)
    else:
        if x > 0:
            print((x - 1) * '+' + (n - x + 1) * '*')
        else:
            x = abs(x)
            print((n - x - 1 ) * '*' + (x + 1) * '-')
