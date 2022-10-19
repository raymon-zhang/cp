def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
 
 
 
for i in range(5):
    line = invr()
    for w in range(5):
        if next(line) == 1:
            print(abs(2-i) + abs(2-w))