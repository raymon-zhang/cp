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
 
 
n = inInt()
 
vert = -10000
 
for i in range(n):
    amount, direction = inSList()
    amount = int(amount)
    if vert == -10000:
        if direction != "South":
            print("NO")
            quit()
    elif vert == 10000:
        if direction != "North":
            print("NO")
            quit()
    if direction == "South":
        vert += amount
    elif direction == "North":
        vert -= amount
    if abs(vert) > 10000:
        print("NO")
        quit()
if vert == -10000:
    print("YES")
else:
    print("NO")