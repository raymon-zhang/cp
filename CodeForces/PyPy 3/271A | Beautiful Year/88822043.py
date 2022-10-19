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
 
def checkSame(s):
    return not len(set(s)) == len(s)
 
n = int(input()) + 1
while checkSame(str(n)):
    n += 1
print(n)