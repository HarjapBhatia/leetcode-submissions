from collections import deque
class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks.sort()
        workers.sort()
        
        n, m = len(tasks), len(workers)
        left, right = 0, min(n, m)
        
        def can_assign(x):
            dq = deque()
            p = pills
            task_idx = 0
            
            for j in range(m - x, m):
                while task_idx < x and tasks[task_idx] <= workers[j] + strength:
                    dq.append(tasks[task_idx])
                    task_idx += 1
                if not dq:
                    return False
                if dq[0] <= workers[j]:
                    dq.popleft()
                elif p > 0:
                    dq.pop()
                    p -= 1
                else:
                    return False
            return True

        while left < right:
            mid = (left + right + 1) // 2
            if can_assign(mid):
                left = mid
            else:
                right = mid - 1
        
        return left
