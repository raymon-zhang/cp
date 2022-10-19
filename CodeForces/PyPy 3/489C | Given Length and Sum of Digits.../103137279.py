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
 
 
def can(m, s):
    return s >= 0 and s <= 9 * m
 
 
m, s = inIList()
sum = s
minn = ""
for i in range(m):
    for d in range(10):
        if (i > 0 or d > 0 or (m == 1 and d == 0)) and can(m - i - 1, sum - d):
            minn += str(d)
            sum -= d
            break
    else:
        minn = -1
        break
 
sum = s
maxn = ""
for i in range(m):
    for d in range(9, -1, -1):
        if (i > 0 or d > 0 or (m == 1 and d == 0)) and can(m - i - 1, sum - d):
            maxn += str(d)
            sum -= d
            break
    else:
        maxn = -1
        break
 
print(minn, maxn)