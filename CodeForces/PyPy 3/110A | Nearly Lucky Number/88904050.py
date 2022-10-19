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
 
def luck(c):    
    for ch in str(c):
        if not (ch == '4' or ch == '7'):
            return False
    return True
 
 
 
 
n = input()[:-1]
 
c = 0
for ch in n:
    if ch == '4' or ch == '7':
        c += 1
 
print("YES" if luck(c) else "NO")
 
    