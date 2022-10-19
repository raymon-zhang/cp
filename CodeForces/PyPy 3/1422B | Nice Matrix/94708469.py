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
    
 
 
def solve():
    n, m = inIList()
    matrix = []
    for i in range(n):
        matrix.append(inIList())
    cost = 0
    for i in range((n)//2):
        for j in range((m)//2):
            x1 = matrix[i][j]
            x2 = matrix[i][m-1-j]
            x3 = matrix[n-1-i][j]
            x4 = matrix[n-1-i][m-1-j]
            l = [x1, x2, x3, x4]
            l.sort()
            med1 = l[1]
            med2 = l[2]
            c1 = abs(med1-x1) + abs(med1-x2) + abs(med1-x3)+ abs(med1-x4)
            c2 = abs(med2-x1) + abs(med2-x2) + abs(med2-x3)+ abs(med2-x4)
            cost += min(c1, c2)
 
    if n%2 == 1:
        for j in range((m)//2):
            x1 = matrix[(n+1)//2-1][j]
            x2 = matrix[(n+1)//2-1][m-1-j]
            avg = (x1+x2)/2
            c = abs(avg-x1) + abs(avg-x2)
            cost += c
            
    if m%2 == 1:
        for j in range((n)//2):
            x1 = matrix[j][(m+1)//2-1]
            x2 = matrix[n-1-j][(m+1)//2-1]
            avg = (x1+x2)/2
            c = abs(avg-x1) + abs(avg-x2)
            cost += c
    print(int(cost))
 
tests = inInt()
for case in range(tests):    
    solve()