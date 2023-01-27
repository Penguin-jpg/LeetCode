from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        current = self.reverse(head)
        n -= 1
        if n == 0:
            return self.reverse(current.next)
        previous, next, dummy = None, current, current
        counter = 0
        while current is not None:
            next = current.next
            if counter == n:
                previous.next = next
                break
            previous = current
            current = next
            counter += 1
        return self.reverse(dummy)

    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        previous, current, next = None, head, head
        while current is not None:
            next = current.next
            current.next = previous
            previous = current
            current = next
        return previous
