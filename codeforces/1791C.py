t = int(input())

for _ in range(t):
    size = int(input())
    tstr = input()

    offset = 0
    diff = 0
    while True:
        left_idx, right_idx = offset, size - offset - 1

        if left_idx >= right_idx:
            break

        left, right = int(tstr[left_idx]), int(tstr[right_idx])

        if left + right == 1:
            offset += 1
        else:
            break
    
    diff += offset * 2
    print(size - diff)
