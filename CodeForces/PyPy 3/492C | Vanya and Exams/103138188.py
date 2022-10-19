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
 
 
n, r, avg = inIList()
ab = []
 
s = 0
cost = 0
 
for i in range(n):
    ia, ib = inIList()
    s += ia
    ab.append([ib, ia])
 
ab = sorted(ab, key=lambda x: x[0])
 
i = 0
 
while s < avg * n:
    t = min(avg * n - s, r - ab[i][1])
    cost += t * ab[i][0]
    s += t
    i += 1
 
print(cost)