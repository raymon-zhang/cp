import math
import sys
from sys import stdin, stdout
 
ipi = lambda: int(stdin.readline())
ipil = lambda: map(int, stdin.readline().split())
ipf = lambda: float(stdin.readline())
ipfl = lambda: map(float, stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x: stdout.write(str(x) + "\n")
outl = lambda x: print(*x)
 
n = ipi()
s = ips()
 
a_cnt = 0
ab_cnt = 0
qst_cnt = 0
ans = 0
 
mod = int(1e9 + 7)
 
for i in range(n):
    if s[i] == 'a':
        a_cnt += pow(3, qst_cnt, mod)
    elif s[i] == 'b':
        ab_cnt += a_cnt
    elif s[i] == 'c':
        ans += ab_cnt
    else:
        ans *= 3
        ans += ab_cnt
        ab_cnt *= 3
        ab_cnt += a_cnt
        a_cnt *= 3
        a_cnt += pow(3, qst_cnt, mod)
        qst_cnt += 1
    a_cnt %= mod
    ab_cnt %= mod
    ans %= mod
 
print(ans)