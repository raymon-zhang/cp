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
def YesNo(ans):print("Yes" if ans else "No")
 
def solve(a, n):
    for i in range(n):
        while True:
            if a[i] % 2 == 0:
                a[i] /=2
            elif a[i] % 3 == 0:
                a[i] /=3
            else:
                break
    YesNo(max(a) == min(a))
 
n = inInt()
a = inIList()
solve(a, n)