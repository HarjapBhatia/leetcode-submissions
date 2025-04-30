class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums)):
            if len(str(abs(nums[i])))%2 == 0: cnt+=1
        return cnt
