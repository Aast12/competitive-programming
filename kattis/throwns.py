n, k = map(int, input().split())

commands = [t if t == "undo" else int(t) for t in input().split()]

history = [0]
eggpos = 0
undo = False
for cmd in commands:
    if cmd == "undo":
        undo = True
    elif undo:
        history = history[:-cmd]
        eggpos = history[-1]
        undo = False
    else:
        eggpos = (eggpos + (cmd % n)) % n
        history.append(eggpos)

print(eggpos)