_ = input()
n = int(input())

alts= []
for _ in range(n):
    ans = input().split(', ')
    alts.append(ans)

best = -1
best_idx = []
for i, ans_alt in enumerate(alts):
    max_changes = 0
    for j, cmp_alt in enumerate(alts): 
        if i == j:
            continue
        curr_changes = 0
        for part, cmp_part in zip(ans_alt, cmp_alt):
            if part != cmp_part:
                curr_changes += 1

        max_changes = max(curr_changes, max_changes)
        
    if best == -1 or max_changes <= best:
        if max_changes < best:
            best_idx = [i]
        else:
            best_idx.append(i)
        best = max_changes

for i in best_idx:
    print(', '.join(alts[i]))