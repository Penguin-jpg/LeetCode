from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        current = head
        nums = []
        while current is not None:
            nums.append(current.val)
            current = current.next
        nums.sort()
        current = head
        for num in nums:
            current.val = num
            current = current.next
        return head
