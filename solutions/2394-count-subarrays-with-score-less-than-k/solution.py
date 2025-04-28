class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        left, right, s, count = 0,0,0,0
        for right in range(len(nums)):
            s += nums[right]
            while s * (right - left + 1) >= k:
                s -= nums[left]
                left +=1  
            count += right-left+1
        return count

