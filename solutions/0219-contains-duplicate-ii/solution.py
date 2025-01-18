class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        res = {}
        for i, num in enumerate(nums):
            if num in res:
                if abs(i-res[num])<=k:
                    return True            
            res[num] = i
        return False
    
        
