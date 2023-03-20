from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        odd_dummy, even_dummy = ListNode(0), ListNode(0)
        odd, even = odd_dummy, even_dummy
        counter, current = 1, head
        while current is not None:
            if counter % 2 == 1:
                odd.next = current
                odd = odd.next
            else:
                even.next = current
                even = even.next
            current = current.next
            counter += 1
        even.next = None
        odd.next = even_dummy.next
        return odd_dummy.next
