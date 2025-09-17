class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # n = len(nums)
        # nums.sort()
        # for j in range(n):
        #     if nums[j] != j+1: return j+1
        # return n+1

        nums.sort()
        smallest = 1
        for num in nums:
            if num == smallest: smallest += 1
        return smallest
