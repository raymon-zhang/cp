import sys
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s-1)]))
def invr():
    return(map(int,input().split()))
 
 
rows = []
rows.append(inlt())
rows.append(inlt())
rows.append(inlt())
amount = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for r in range(3):
    for c in range(3):
        cell = rows[r][c]
        amount[r][c] += cell
        if r - 1 >= 0:
            amount[r-1][c] += cell
        if r + 1 < 3:
            amount[r+1][c] += cell
        if c - 1 >= 0:
            amount[r][c - 1] += cell
        if c + 1 < 3:
            amount[r][c + 1] += cell
 
for row in range(3):
    for column in range(3):
        cell = amount[row][column]
        if cell % 2 == 0:
            amount[row][column] = 1
        else: amount[row][column] = 0
for row in amount:
    for cell in row:
        print(cell, end = "")
    print()