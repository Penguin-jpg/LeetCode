from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        table = {}
        current = headA
        while current is not None:
            table[current] = True
            current = current.next
        current = headB
        while current is not None:
            if current in table:
                return current
            current = current.next
        return None
