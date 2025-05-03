class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def check(target):
            rotate_cnt_top = rotate_cnt_bottom = 0
            for i in range(len(tops)):
                if tops[i]!=target and bottoms[i] != target:
                    return -1
                elif tops[i] != target:
                    rotate_cnt_top += 1
                elif bottoms[i] != target:
                    rotate_cnt_bottom += 1
            return min(rotate_cnt_top, rotate_cnt_bottom)

        res = check(tops[0])
        if res != -1:
            return res
        if tops[0] != bottoms[0]:
            res = check(bottoms[0])
            if res != -1:
                return res
        return -1

