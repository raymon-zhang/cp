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
 
s = input()[:-1]
 
u = 0
for c in s:
    if c.isupper():
        u += 1
if u >= len(s)//2+1:
    s = s.upper()
else:
    s = s.lower()
 
print(s)