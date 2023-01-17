from typing import Optional
from collections import deque


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        nums = deque()
        current = head
        while current is not None:
            nums.append(current.val)
            current = current.next
        size = len(nums)
        for _ in range(0, size // 2):
            if nums.popleft() != nums.pop():
                return False
        return len(nums) == 0 or len(nums) == 1
