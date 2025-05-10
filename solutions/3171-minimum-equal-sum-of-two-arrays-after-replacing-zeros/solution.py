class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        zero1 = sum1 = 0
        zero2 = sum2 = 0
        for i in nums1:
            if i==0:
                zero1 +=1
            else:
                sum1 += i
        min_sum1 = sum1+zero1
        
        for i in nums2:
            if i==0:
                zero2 +=1
            else:
                sum2 += i
        min_sum2 = sum2+zero2

        if min_sum1 == min_sum2:
            return min_sum1
        elif min_sum1 > min_sum2:
            if zero2 == 0:
                return -1
            else:
                return min_sum1
        else:
            if zero1 == 0:
                return -1
            else:
                return min_sum2
