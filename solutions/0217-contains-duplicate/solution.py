class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        counts = defaultdict(int)
    
        for num in nums:
            counts[num] += 1
            if counts[num] >= 2:
                return True
        return False
