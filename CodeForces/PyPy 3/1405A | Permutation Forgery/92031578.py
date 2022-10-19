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
 
def bsearch(nums, target):
    N = len(nums or [])
    l = 0
    r = N - 1
 
    while l <= r:
        mid = ((l + r) // 2)
        if nums[mid] < target:
            l = mid + 1
        elif nums[mid] > target:
            r = mid - 1
        else:
            return (None, mid, None)
 
    return (r if r >= 0 else None, None, l if l <= N-1 else None)
 
def yesOrNo(val):
    print("YES" if val else "NO")
def printSpacedArray(nums):
    for x in nums:
        print(x, end = " ")
    print()
 
def solve():
    n = inInt()
    case = inIList()
    case.reverse()
    printSpacedArray(case)
 
tests = inInt()
for case in range(tests):    
    solve()