#----------Input functions-------------
import sys
input = sys.stdin.readline
def inInt():
    return int(input())
def inStr():
    return input().strip("\n")
def inIList():
    return(list(map(int,input().split())))
def inSList():
    return(input().split())
 
# def isGood(nums):
#     for i in range(len(nums)):
#         for j in range(i, len(nums)):
#             res = 0
#             for e in nums[i:j + 1]:
#                 res |= e
#             if res < (j + 1) - (i + 1) + 1:
#                 return False
#     return True
 
# def permute(a):
#     return list(itertools.permutations(a))
def solve(n):
    #----solution here----
    for x in list(range(1, n+1)):
        print(x, end = ' ')
    print()
 
tests = inInt()
for case in range(tests):
    # ------take input here------
    n = inInt()
 
    solve(n)
    