from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = self.get_length(head)
        if length == n:
            return head.next
        previous, current, next = None, head, head
        target, counter = length - n, 0
        while current is not None:
            next = current.next
            if counter == target:
                previous.next = next
                break
            previous = current
            current = next
            counter += 1
        return head

    def get_length(self, head: Optional[ListNode]) -> int:
        length, current = 0, head
        while current is not None:
            length += 1
            current = current.next
        return length
