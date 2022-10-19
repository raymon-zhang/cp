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
    h, w = inIList()
 
    m = []
    for i in range(h):
        m.append(inStr())
 
    hs = None
 
    started = False
    ended = False
    actuallyended = False
 
    hor = False
 
    
 
    for i in range(h):
        count = 0
        spot = None
        length = 0
        start = 0
        end = 0
        for j in range(w):
            if m[i][j] == "*":
                if end:
                    return "NO"
                if length == 0:
                    start = j
                length += 1
                count += 1
                spot = j
            else:
                if length:
                    end = j
 
        if count > 1:
            if not end:
                end = w
            if hs:
                if not(hs > start and hs < end-1):
                    return "NO"
            else:
                return "NO"
            if not hor:
                hor = True
            else:
                return "NO"
        if count == 1:
            if not started:
                hs = spot
                started = True
            elif actuallyended:
                return "NO"
            elif spot == hs:
                if hor:
                    ended = True
            else:
                return "NO"
        if count == 0:
            if started:
                if not ended:
                    return "NO"
                else:
                    actuallyended = True
    if started and ended and hs != None and hor:
        return "YES"
 
    return "NO"
 
 
print(solve())