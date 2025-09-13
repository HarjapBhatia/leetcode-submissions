class Solution:
    def maxFreqSum(self, s: str) -> int:
        hs = {}
        for ch in s:
            if ch in hs: hs[ch]+=1
            else: hs[ch]=1
        
        vowels = ['a', 'e', 'i', 'o', 'u']
        mxV=0
        mxC=0
        for ch, cnt in hs.items():
            if ch in vowels: mxV = max(mxV, cnt)
            else: mxC = max(mxC, cnt)

        return mxV+mxC 

