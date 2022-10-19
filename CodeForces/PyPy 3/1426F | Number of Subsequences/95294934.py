import sys
import math
input = sys.stdin.readline
 
def inInt():
    return int(input())
 
def inStr():
    return input().rstrip()
 
 
 
a = 0
ab = 0
abc = 0
q = 0
m = int(1e9 + 7)
n = inInt()
s = inStr()
for i in range(n):
    if s[i] == "a":
        a += pow(3, q, m)
    elif s[i] == "b":
        ab += a
    elif s[i] == "c":
        abc += ab
    else:
        abc *= 3
        abc += ab
        ab *= 3
        ab += a
        a *= 3
        a += pow(3, q, m)
        q += 1
    a %= m
    ab %= m
    abc %= m
print(abc)