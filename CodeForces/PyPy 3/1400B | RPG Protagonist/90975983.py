import sys
 
input = sys.stdin.readline
 
def inInt():
    return int(input())
 
def inStr():
    return input().strip("\n")
 
def inIList():
    return (list(map(int, input().split())))
 
def inSList():
    return (input().split())
 
 
 
 
 
def solve(p, f, cs, cw, s, w):
    
    pc, fc = 0, 0
    sols = []
    ss = False
    if s < w:
        ss = True
    
    if ss:
        for i in range(cs + 1):
            pc = min(p // s, i)
            pr = p - (pc * s)
            fc = min(f // s, cs - i)
            fr = f - (fc * s)
            o = 0
            o += pr // w
            o += fr // w
            o = min(cw, o)
            sols.append(pc + fc + o)
        print(max(sols))
    else:
        for i in range(cw + 1):
            pc = min(p // w, i)
            pr = p - (pc * w)
            fc = min(f // w, cw - i)
            fr = f - (fc * w)
            o = 0
            o += pr // s
            o += fr // s
            o = min(cs, o)
            sols.append(pc + fc + o)
        print(max(sols))
 
tests = inInt()
 
for t in range(tests):
    p_and_f = inIList()
    p = p_and_f[0]
    f = p_and_f[1]
 
    cs_and_cw = inIList()
    cs = cs_and_cw[0]
    cw = cs_and_cw[1]
 
    s_and_w = inIList()
    s = s_and_w[0]
    w = s_and_w[1]
 
    solve(p, f, cs, cw, s, w)