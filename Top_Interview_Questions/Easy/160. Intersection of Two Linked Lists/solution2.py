from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        length_a = self.get_length(headA)
        length_b = self.get_length(headB)
        diff = abs(length_a - length_b)
        if length_a > length_b:
            for i in range(diff):
                headA = headA.next
        else:
            for i in range(diff):
                headB = headB.next
        currentA, currentB = headA, headB
        while currentA is not None and currentB is not None:
            if currentA == currentB:
                return currentA
            currentA = currentA.next
            currentB = currentB.next
        return None

    def get_length(self, head: ListNode):
        current = head
        length = 0
        while current is not None:
            length += 1
            current = current.next
        return length
