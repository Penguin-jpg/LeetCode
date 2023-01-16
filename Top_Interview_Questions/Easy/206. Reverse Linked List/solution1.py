from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        pre, current, next = None, head, head
        while current is not None:
            next = current.next
            current.next = pre
            pre = current
            current = next
        return pre
