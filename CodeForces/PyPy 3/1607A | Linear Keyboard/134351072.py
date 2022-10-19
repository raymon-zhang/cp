t = int(input())
 
for i in range(t):
    keyboard = input()
    keys = {}
    for j, c in enumerate(keyboard):
        keys[c] = j
 
    word = input()
 
    distance = 0
 
    for n in range(1, len(word)):
        distance += abs(keys[word[n]] - keys[word[n-1]])
 
    print(distance)