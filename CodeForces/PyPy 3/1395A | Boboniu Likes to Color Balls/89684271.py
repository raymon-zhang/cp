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
 
def isPal(c):
    odd = 0
    for n in c:
        odd += n % 2 == 1
    if odd <= 1:
        return True
    elif odd == 3:
        return c[0] > 0 and c[1] > 0 and c[2] > 0
    elif odd == 4:
        return True
 
 
def solve(c):
    if isPal(c):
        print("Yes")
    else:
        print("No")
    
 
t = inInt()
for c in range(t):
    case = inIList()
    solve(case)