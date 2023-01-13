from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        table = {}
        current = head
        while current is not None:
            if current in table:
                return True
            table[current] = True
            current = current.next
        return False
