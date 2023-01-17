from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        slow = self.reverse_list(slow)
        fast = head
        while slow is not None:
            if slow.val != fast.val:
                return False
            slow = slow.next
            fast = fast.next
        return True

    def reverse_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre, current, next = None, head, head
        while current is not None:
            next = current.next
            current.next = pre
            pre = current
            current = next
        return pre
