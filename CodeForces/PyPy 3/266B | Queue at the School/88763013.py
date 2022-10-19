def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().split()))
 
l1 = invr()
time = next(l1)
time = next(l1)
l2 = insr()
nl2 = l2.copy()
 
for t in range(time):
    for x in range(len(l2)-1):
        if l2[x] == 'B' and l2[x+1] == 'G':
            nl2[x] = 'G'
            nl2[x+1] = 'B'
    l2 = nl2.copy()
 
print(''.join(l2))