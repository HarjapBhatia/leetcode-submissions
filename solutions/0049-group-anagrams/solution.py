class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res  = defaultdict(list)
        for s in strs:
            arr = [0]*26
            for word in s:
                arr[ord(word)-ord("a")] += 1
            res[tuple(arr)].append(s)
        return list(res.values())
