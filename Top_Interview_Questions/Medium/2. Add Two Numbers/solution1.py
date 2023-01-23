from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum, carry = 0, 0
        dummy = ListNode(0)
        result = dummy
        current1, current2 = l1, l2
        while current1 is not None and current2 is not None:
            sum = current1.val + current2.val + carry
            result.next = ListNode(sum % 10)
            carry = sum // 10
            current1 = current1.next
            current2 = current2.next
            result = result.next
        while current1 is not None:
            sum = current1.val + carry
            result.next = ListNode(sum % 10)
            carry = sum // 10
            current1 = current1.next
            result = result.next
        while current2 is not None:
            sum = current2.val + carry
            result.next = ListNode(sum % 10)
            carry = sum // 10
            current2 = current2.next
            result = result.next
        if carry == 1:
            result.next = ListNode(carry)
        return dummy.next
