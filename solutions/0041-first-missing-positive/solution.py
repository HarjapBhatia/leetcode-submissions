class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        i=0
        while i<n:
            x = nums[i]
            if 1<=x<=n and nums[x-1]!=x:
                nums[i], nums[x-1] = nums[x-1], nums[i]
            else: i += 1

        for j in range(n):
            if nums[j] != j+1: return j+1
        return n+1
