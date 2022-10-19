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
 
def solve(n, case):
    freq = {}
    freq[1] = 1
    s = 0
    res = 0
    for i in range(n):
        s += int(case[i])
        if s - i not in freq:
            freq[s-i] = 0
        res += freq[s - i]
        freq[s - i] += 1
    print(res)
t = inInt()
for case in range(t):
    n = inInt()
    case = inStr()
    solve(n, case)