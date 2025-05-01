# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        s1 = ""
        s2 = ""

        while l1:
            s1 += str(l1.val)
            l1 = l1.next

        while l2:
            s2 += str(l2.val)
            l2 = l2.next

        num1 = int(s1[::-1])
        num2 = int(s2[::-1])
        total = num1 + num2
        total_str = str(total)[::-1]

        dummy = ListNode(0)
        current = dummy
        for digit in total_str:
            current.next = ListNode(int(digit))
            current = current.next

        return dummy.next
