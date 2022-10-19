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
 
def solve(case, n):
    s = case.copy()
    s.sort()
    count = 0
    for i in range(n):
        if case[i] != s[i]:
            count += 1
    print("YES" if count <= 2 else "NO")
 
tests = inInt()
case = inIList()
solve(case, tests)