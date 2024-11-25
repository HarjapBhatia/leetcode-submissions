class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        num = x
        r = 0
        while x != 0:
            r = r * 10 + x % 10
            x //= 10
        
        return num == r

