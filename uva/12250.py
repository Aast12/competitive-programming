languages = {
"HELLO": "ENGLISH",
"HOLA": "SPANISH",
"HALLO": "GERMAN",
"BONJOUR": "FRENCH",
"CIAO": "ITALIAN",
"ZDRAVSTVUJTE": "RUSSIAN"
}

caseno = 1

while True:
    word = input()
    if word == "#":
        break
    if word in languages:
        print("Case " + str(caseno) + ": " + languages[word])
    else:
        print("Case " + str(caseno) + ": UNKNOWN")
    
    caseno += 1
