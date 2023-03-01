n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    
    if abs(a - b) == 1:
        if max(a, b) % 2 == 0:
            print("CHEF")
        else:
            print("CHEFINA")
    elif a > b:
        print("CHEF")
    elif b > a:
        print("CHEFINA")
    else:
        if a % 2 == 0:
            print("CHEFINA")
        else:
            print("CHEF")