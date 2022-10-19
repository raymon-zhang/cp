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
 
def solve(nums):
    ones = nums.split("0")
    res = [i for i in ones if i != ""]
    lens = [len(i) for i in res]
    a = 0
    turn = True
    while lens:
        if turn:
            a += max(lens)
            lens.remove(max(lens))
            turn = False
        else:
            lens.remove(max(lens))
            turn = True
    print(a)
 
t = inInt()
for case in range(t):
    nums = inStr()
    solve(nums)