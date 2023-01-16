from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        return self.reverse(None, head)

    def reverse(self, pre: Optional[ListNode], current: Optional[ListNode]) -> Optional[ListNode]:
        if current is None:
            return pre
        next = current.next
        current.next = pre
        return self.reverse(current, next)
