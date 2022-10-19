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
 
def solve(case, d):
    ans = 0
    j = 0
    for i in range(len(case)):
        while case[i] - case[j] > d:j += 1
        ans += int((i - j) * (i - j - 1)/2)
            
 
    print(ans)
 
nums = inIList()
case = inIList()
solve(case, nums[1])