class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        res = defaultdict(int)
        for num in nums:
            res[num]+=1
        sorted_nums = sorted(res, key=res.get, reverse=True)
        return sorted_nums[:k]
