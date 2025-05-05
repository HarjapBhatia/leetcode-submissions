from collections import defaultdict
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count = defaultdict(int)
        for domino in dominoes:
            sorted_domino = tuple(sorted(domino))
            count[sorted_domino] += 1
        count_sorted = sorted(count.values())
        res = 0
        for n in count.values():
            res += n * (n-1)//2
        return res
