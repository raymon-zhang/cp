import sys
input = sys.stdin.readline
# def inp():
#     return(int(input()))
# def inlt():
#     return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s-1)]))
# def invr():
#     return(map(int,input().split()))
 
s = input()
 
m = { '-.': "1", '--':"2"}
 
i = 0
out = ""
while i < len(s):
    if s[i] == ".":
        out += "0"
    elif s[i] == "-":
        out += m[s[i:i+2]]
        i += 1
    i += 1
print(out)