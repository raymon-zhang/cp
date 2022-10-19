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
 
def solve(n, a, b, c):
    if n % 4 == 0: print(0)
    elif n % 4 == 1: print(min(3 * a, a + b, c))
    elif n % 4 == 2: print(min(2 * a, b, 2 * c))
    else: print(min(a, c * 3, c + b))
 
nabc = inIList()
n, a, b, c = nabc[0], nabc[1], nabc[2], nabc[3]
solve(n, a, b, c)