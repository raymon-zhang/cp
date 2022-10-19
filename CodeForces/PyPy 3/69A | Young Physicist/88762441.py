 
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(list(map(int,input().split())))
 
l = inp()
x = 0
y = 0
z = 0
for i in range(l):
    line = invr()
    x += line[0]
    y += line[1]
    z += line[2]
if x == y == z == 0:
    print("YES")
else: print("NO")