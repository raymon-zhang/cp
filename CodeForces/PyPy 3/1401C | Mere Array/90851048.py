# f5fa6e48ca9037ccdd80c63dbd3ec966ced2b6290e6ee666d5f3df8b1964bffc
import sys
import math
input = sys.stdin.readline
def inInt():
    return int(input())
def inStr():
    return input().strip("\n")
def inIList():
    return(list(map(int,input().split())))
def inSList():
    return(input().split())
 
def solve():
    n = inInt()
    a = inIList()
    sa = a.copy()
    sa.sort()
    m = min(a)
    for x in range(len(sa)):
        if sa[x] == a[x]: continue
        if sa[x] % m != 0:
            return False
    
 
    return True
 
 
tests = inInt()
for case in range(tests):    
    print("YES" if solve() else "NO")