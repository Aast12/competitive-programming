letters = input()[1:-1].split(', ')
if '' in letters:
    letters.remove('')
letter_set = set(letters)

print(len(letter_set))