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
    nk = inIList()
    n, k = nk[0], nk[1]
    s = inStr()
    out = [(s[i:i+k]) for i in range(0, len(s), k)]
    spots = []
    for i in range(k):
        count1s = 0
        count0s = 0
        for n in out:
            if len(n) > i:
                if n[i] == '0':
                    count0s += 1
                elif n[i] == '1':
                    count1s += 1
        if count1s == 0 and count0s == 0:
            spots.append('?')
        elif count1s > 0 and count0s > 0:
            return "NO"
        elif count1s > 0:
            spots.append('1')
        else:
            spots.append('0')
    if spots.count('0') <= k/2 and spots.count('1') <= k/2:
        return "YES"
    return "NO"
                
 
 
tests = inInt()
for case in range(tests):    
    print(solve())