class Solution:
    def isPalindrome(self, x: int) -> bool:
        temp = x
        res = 0
        if x < 0: return False
        while temp!=0:
            rem = temp %10
            res = 10*res + rem
            temp = temp // 10
        return res == x
