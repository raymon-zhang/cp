import sys
input = sys.stdin.readline
def inInt():
    return int(input())
def inStr():
    return input().strip("\n")
def inIList():
    return(list(map(int,input().split())))
def inSList():
    return(input().split())
 
case = inIList()
n = case[1]
m = case[0]
sx, sy = case[2], case[3]
cx, cy = sx, sy
for i in range(m - sx + 1):
    print(sx + i, sy)
for i in range(1, sx):
    print(sx - i, sy)
sx = 1
sy -= 1
while sy > 0:
    print(sx, sy)
    for i in range(m - 1):
        sx += 1
        print(sx, sy) 
    sy -= 1
    if sy == 0:
        break
    print(sx, sy) 
    for i in range(m - 1):
        sx -= 1
        print(sx, sy) 
    sy -= 1
sy = cy + 1
if sx == 1:
    while sy <= n:
        print(sx, sy)
        for i in range(m - 1):
            sx += 1
            print(sx, sy)
        sy += 1
        if sy > n:
            break
        print(sx, sy)
        for i in range(m - 1):
            sx -= 1
            print(sx, sy)
        sy += 1
elif sx == m:
    while sy <= n:
        print(sx, sy)
        for i in range(m - 1):
            sx -= 1
            print(sx, sy)
        sy += 1
        if sy > n:
            break
        print(sx, sy)
        for i in range(m - 1):
            sx += 1
            print(sx, sy)
        sy += 1