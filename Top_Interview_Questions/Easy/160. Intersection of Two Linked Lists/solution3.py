from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        currentA, currentB = headA, headB
        while currentA != currentB:
            currentA = currentA.next if currentA is not None else headB
            currentB = currentB.next if currentB is not None else headA
        return currentA
