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
    print(*nums)
 
 
 
def solve():
    n,T = inIList()
    t = T/2
    nums = inIList()
    
    res = []
    if T%2:
        for i in range(n):
            if nums[i] < t:
                res.append(0)
            else:
                res.append(1)
    else:
        h = 0
        for i in nums:
            if i == t:
                h += 1
 
        s = 0
        for i in range(n):
            if nums[i] < t:
                res.append(0)
            elif nums[i] > t:
                res.append(1)
            else:
                if s < h/2:
                    res.append(0)
                else:
                    res.append(1)
                s += 1
                
                        
    print(*res)
                
 
tests = inInt()
for case in range(tests):    
    solve()