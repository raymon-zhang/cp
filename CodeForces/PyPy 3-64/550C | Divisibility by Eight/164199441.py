import sys
input = sys.stdin.readline
 
 
def inInt():
    return int(input())
 
 
def inStr():
    return input().strip("\n")
 
 
def inIList():
    return(list(map(int, input().split())))
 
 
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
    n = inStr()
 
    for i in range(len(n)):
        if int(n[i]) % 8 == 0:
            return n[i]
    
    if len(n) >= 2:
        for i in range(len(n)):
            for j in range(i+1, len(n)):
                a = n[i]
                b = n[j]
                if int(a+b) % 8 == 0:
                    return a+b
 
    if len(n) >= 3:
        for i in range(len(n)):
            for j in range(i+1, len(n)):
                for k in range(j+1, len(n)):
                    a = n[i]
                    b = n[j]
                    c = n[k]
                    if int(a+b+c) % 8 == 0:
                        return a+b+c
 
    return "NO"
x = solve()
if x != "NO":
    print("YES")
    print(x)
else:
    print(x)