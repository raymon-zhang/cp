n = int(input())
results = []
 
for t in range(n):
    n = input()
    count = 0
    nums1 = list(map(int,input().split()))
    n1 = min(nums1)
    nums2 = list(map(int,input().split()))
    n2 = min(nums2)
    for i in range(len(nums1)):
        diff = min(nums1[i] - n1, nums2[i] - n2)
        count += diff
        count += nums1[i] - n1 - diff
        count += nums2[i] - n2 - diff
    results.append(count)
 
for _ in results:
    print(_)