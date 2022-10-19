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
    grid = []
    n, m = inIList()
    for i in range(n):
        grid.append(list(inStr()))
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "B":
                if i > 0:
                    if grid[i-1][j] == ".":
                        grid[i-1][j] = "#"
                if i < n-1:
                    if grid[i+1][j] == ".":
                        grid[i+1][j] = "#"
                if j > 0:
                    if grid[i][j-1] == ".":
                        grid[i][j-1] = "#"
                if j < m-1:
                    if grid[i][j+1] == ".":
                        grid[i][j+1] = "#"
 
    queue = []
    seen = [[False for j in range(m)] for i in range(n)]
 
    queue.append((n-1, m-1))
    while queue:
        cur = queue[0]
        queue = queue[1:]
        if not seen[cur[0]][cur[1]] and grid[cur[0]][cur[1]] != "#":
            i, j = cur
            seen[i][j] = True
            if i > 0:
                queue.append((i-1, j))
            if i < n-1:
                queue.append((i+1, j))
            if j > 0:
                queue.append((i, j-1))
            if j < m-1:
                queue.append((i, j+1))
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "B":
                if seen[i][j]:
                    return "No"
            elif grid[i][j] == "G":
                if not seen[i][j]:
                    return "No"
    return "Yes"
 
 
tests = inInt()
for case in range(tests):
    print(solve())