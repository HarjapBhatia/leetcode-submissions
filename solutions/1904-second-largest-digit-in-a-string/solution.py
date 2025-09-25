class Solution:
    def secondHighest(self, s: str) -> int:
        l = []
        for i in s:
            if i.isnumeric():
                i = int(i)
                l.append(i)
        
        smx = mx = -1

        for x in l:
            if x > mx:
                smx = mx
                mx = x
            elif x > smx and x < mx: smx = x

        return smx 
