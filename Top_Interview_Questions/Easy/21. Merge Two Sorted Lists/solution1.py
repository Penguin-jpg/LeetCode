from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        elif list2 is None:
            return list1

        dummy = ListNode()
        result = dummy
        current1, current2 = list1, list2

        while current1 is not None and current2 is not None:
            if current1.val < current2.val:
                result.next = current1
                current1 = current1.next
            else:
                result.next = current2
                current2 = current2.next
            result = result.next

        result.next = current1 if current1 is not None else current2
        return dummy.next
