import sys
 
input = sys.stdin.readline
 
 
def inInt():
    return int(input())
 
 
def inStr():
    return input().strip("\n")
 
 
def inIList():
    return list(map(int, input().split()))
 
 
def inSList():
    return input().split()
 
 
def bsearch(nums, target):
    N = len(nums or [])
    l = 0
    r = N - 1
 
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] < target:
            l = mid + 1
        elif nums[mid] > target:
            r = mid - 1
        else:
            return (None, mid, None)
 
    return (r if r >= 0 else None, None, l if l <= N - 1 else None)
 
 
def yesOrNo(val):
    print("YES" if val else "NO")
 
 
def printSpacedArray(nums):
    print(*nums)
 
 
def solve():
    n, k = inIList()
    h = inIList()
 
    top = bottom = 0
 
    for i in range(n):
        if i == 0:
            top = bottom = h[i]
        else:
            bottom = max(bottom - k + 1, h[i])
            top = min(top + k - 1, h[i] + k - 1)
 
        if top < bottom:
            return "NO"
    if bottom != h[-1]:
        return "NO"
    return "YES"
 
 
tests = inInt()
for case in range(tests):
    print(solve())