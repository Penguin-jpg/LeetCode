from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        current1, current2 = l1, l2
        dummy = ListNode(0)
        result = dummy
        while carry != 0 or current1 is not None or current2 is not None:
            if current1 is not None:
                carry += current1.val
                current1 = current1.next
            if current2 is not None:
                carry += current2.val
                current2 = current2.next
            result.next = ListNode(carry % 10)
            carry //= 10
            result = result.next
        return dummy.next
