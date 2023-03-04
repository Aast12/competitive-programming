import functools

t = int(input())

scores = {
    'lower': 0,
    'middle': 1,
    'upper': 2,
}
def encode_class(sclass, padding):
    score = 0
    n = len(sclass)
    for i in range(padding - n):
        score += (3 ** i)

    for i in range(n):
        p = i + padding - n
        part = sclass[i]
        score += scores[part] * (3 ** p)

    return score

while t > 0:
    n = int(input())
    classes = []
    largest_level = 0
    for _ in range(n):
        line = input()
        name, sclass = line.split()[:-1]
        name = name[:-1]
        sclass = sclass.split('-')

        if len(sclass) > largest_level:
            largest_level = len(sclass)
        
        classes.append((name, sclass))
    
    classes_enc = [[name, encode_class(sclass, largest_level)] for name, sclass in classes]
    def cmp(fst, snd):
        if fst[1] == snd[1]:
            return 1 if fst[0] > snd[0] else -1
        return 1 if fst[1] < snd[1] else -1

    classes_sorted = sorted(classes_enc, key=functools.cmp_to_key(cmp))
    
    for name, _ in classes_sorted:
        print(name)
    print('=' * 30)
    t -= 1