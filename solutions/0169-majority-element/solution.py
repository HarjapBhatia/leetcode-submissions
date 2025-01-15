class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = defaultdict(int)
        n = len(nums)

        for num in nums:
            count[num] += 1
            if count[num] > n/2:
                return num
        
