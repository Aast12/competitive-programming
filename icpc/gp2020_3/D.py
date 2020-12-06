
t = int(input())

for u in range(t):
    s, k = input().split()
    k = int(k)
    lastno = ""
    current = ""
    feasible = True

    for ch in s:
        if ch.isnumeric():
            lastno += ch
        elif lastno != "":
            if len(current) + int(lastno) > k:
                feasible = False
                break
            current += ch * int(lastno)
            lastno = ""
        else:
            current += ch
            if len(current) > k:
                feasible = False
                break

    if feasible:
        print(current)
    else:
        print("unfeasible")
