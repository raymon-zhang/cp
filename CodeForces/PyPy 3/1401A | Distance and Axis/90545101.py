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
    nk = inIList()
    n, k = nk[0], nk[1]
    if k == 0:
        return 1 if n % 2 == 1 else 0
    if n <= k:
        return k - n
    if n % 2 == k % 2:
        return 0
    return 1
 
tests = inInt()
for case in range(tests):    
    print(solve())