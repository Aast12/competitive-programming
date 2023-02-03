t = int(input())

for _ in range(t):
    _ = input()
    moves = input()

    pos = [0, 0]
    passed = False
    for mov in moves:
        if mov == 'U':
            pos[1] += 1
        elif mov == 'D':
            pos[1] -= 1
        elif mov == 'L':
            pos[0] -= 1
        else:
            pos[0] += 1

        if pos[0] == 1 and pos[1] == 1:
            passed = True
            print('YES')
            break

    if not passed:
        print('NO')