class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1,s = 0,0
        for i in range(1,n+1):
            s +=i
            if not (i%m==0):
                num1 +=i
        return 2*num1-s
