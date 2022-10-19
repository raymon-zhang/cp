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
 
 
n, k, d = inIList()
 
dp = [[0 for i in range(2)] for i in range(101)]
 
dp[0][0] = 1
dp[0][1] = 0
 
for i in range(1, n + 1):
    dp[i][0] = 0
    dp[i][1] = 0
 
    for j in range(1, k + 1):
        if j > i:
            break
 
        if j < d:
            dp[i][0] += dp[i - j][0]
            dp[i][1] += dp[i - j][1]
            dp[i][0] %= 1000000007
            dp[i][1] %= 1000000007
        else:
            dp[i][1] += dp[i - j][0]
            dp[i][1] += dp[i - j][1]
            dp[i][1] %= 1000000007
 
 
print(dp[n][1])