import sys
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s-1)]))
def invr():
    return(map(int,input().split()))
 
number = int(input())
 
lines = []
for line in range(number):
    l = input().split(" ")
    lines.append(l)
scores = {}
for line in lines:
    if not line[0] in scores:
        scores[line[0]] = int(line[1])
    else: scores[line[0]] += int(line[1])
 
m = max(list(scores.values()))
winners = []
for key in scores:
    if scores[key] == m:
        winners.append(key)
 
for n in scores:
    scores[n] = 0
for line in lines:
    scores[line[0]] += int(line[1])
    
    
    if max(list(scores.values())) >= m:
        v=list(scores.values())
        k=list(scores.keys())
        if k[v.index(max(v))] in winners:
            print(k[v.index(max(v))])
            break
    