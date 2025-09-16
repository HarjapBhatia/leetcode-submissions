class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        st = []
        for n in nums:
            while st and math.gcd(st[-1], n) > 1:
                top = st.pop()
                n = (n * top) // math.gcd(n, top)
            st.append(n)
        return st
