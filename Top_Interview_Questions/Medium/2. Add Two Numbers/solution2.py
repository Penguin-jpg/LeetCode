from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        return self.add_lists(l1, l2, 0)

    def add_lists(self, l1: Optional[ListNode], l2: Optional[ListNode], carry: int) -> Optional[ListNode]:
        if l1 is None and l2 is None:
            result = ListNode(carry) if carry == 1 else None
        elif l1 is None:
            result = ListNode((l2.val + carry) % 10)
            result.next = self.add_lists(l1, l2.next, (l2.val + carry) // 10)
        elif l2 is None:
            result = ListNode((l1.val + carry) % 10)
            result.next = self.add_lists(l1.next, l2, (l1.val + carry) // 10)
        else:
            result = ListNode((l1.val + l2.val + carry) % 10)
            result.next = self.add_lists(l1.next, l2.next, (l1.val + l2.val + carry) // 10)
        return result
