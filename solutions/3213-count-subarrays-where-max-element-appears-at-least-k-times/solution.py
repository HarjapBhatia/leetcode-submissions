class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        left, right, sub_array_count, max_element_count = 0,0,0,0
        max_element = max(nums)

        for right in range(len(nums)):
            if nums[right] == max_element:
                max_element_count +=1
            
            while max_element_count >= k:
                sub_array_count += (len(nums) - right)
                if nums[left] == max_element:
                    max_element_count -= 1
                left += 1

        return sub_array_count
