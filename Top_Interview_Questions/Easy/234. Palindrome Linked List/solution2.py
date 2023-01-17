from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        length = self.get_length(head)
        front, back = head, head
        for i in range(0, length // 2):
            back = back.next
        back = self.reverse_list(back)
        while back is not None:
            if front.val != back.val:
                return False
            front = front.next
            back = back.next
        return True

    def get_length(self, head: Optional[ListNode]) -> int:
        length = 0
        current = head
        while current is not None:
            length += 1
            current = current.next
        return length

    def reverse_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre, current, next = None, head, head
        while current is not None:
            next = current.next
            current.next = pre
            pre = current
            current = next
        return pre
