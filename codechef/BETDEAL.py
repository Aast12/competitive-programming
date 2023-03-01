# cook your dish here
n = int(input())
eps = 0.0001

for _ in range(n):
    a, b = [int(x) for x in input().split()]
    d_a, d_b = 100.0 * (1 - a / 100), 200.0 * (1 - b / 100)
    if d_a - d_b > eps:
        print("SECOND")
    elif d_b - d_a > eps:
        print("FIRST")
    else:
        print("BOTH")