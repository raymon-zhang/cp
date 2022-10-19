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
 
def solve():
    a = inIList()
    b = inIList()
    s = 0
    pb = b[2]
    b[2] -= a[0]
    a[0] = max(a[0] - pb, 0)
    if b[2] <= 0:
        b[2] = 0
    else:
        pb = b[2]
        b[2] -= a[2]
        a[2] = max(a[2] - pb, 0)
        if b[2] <= 0:
            b[2] = 0
        else:
            s -= b[2] * 2
    s += 2 * min(a[2], b[1])
    
    return s
 
tests = inInt()
for case in range(tests):    
    print(solve())