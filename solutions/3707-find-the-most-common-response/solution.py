class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:
        freq = defaultdict(int)

        for day in responses:
            response = set(day)
            for s in response:
                freq[s] += 1
        return min(freq.items(), key=lambda x: (-x[1], x[0]))[0] 
