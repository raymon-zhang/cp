def solve(nums):
    for i in range(len(nums)-1):
        if nums[i+1] - nums[i] > 1:
            return False
    return True
 
n = int(input())
results = []
for t in range(n):
    n = int(input())
 
    nums = list(map(int,input().split()))
    nums.sort()
    results.append(solve(nums))
for _ in results:
    if _:
        print("YES")
    else:
        print("NO")