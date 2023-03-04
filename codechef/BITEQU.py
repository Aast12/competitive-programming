def msb(n: int) -> int:
    k = 0
    while (n > 0):
        k += 1
        n >>= 1
    return k

def solve(n: int):
    if n == 0:
        return (6, 5, 0, 4)

    k = msb(n)
    a = 1 << (k + 3)
    b = 1 << (k + 2)
    c = 1 << (k + 1)
    d = n + c

    return (a, b, c, d)

for j in range(2 ** 30, 2 ** 32):
    # q = 2 ** i
    # for j in range(q - 10, q + 10):
        if j < 0:
            continue
        # print(j)
        a, b, c, d = solve(j)

        s = {a, b, c, d}
        if len(s) != 4:
            print("no dist", a, b, c, d)

        res = ((a & b) | c) ^ d
        # print(s)
        if res != j:
            print("no eq", a, b, c, d, res)

print("wuuuu")
# t = int(input())

# for _ in range(t):
#     n = int(input())

#     if n == 0:
#         print(6, 5, 0, 4)
#         continue

#     k = msb(n)
#     a = 1 << (k + 3)
#     b = 1 << (k + 2)
#     c = 1 << (k + 1)
#     d = n + c

#     print(a, b, c, d)
