from typing import List, Optional
import sys


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        k = len(lists)
        dummy = ListNode()
        result = dummy
        while True:
            counter = 0
            for head in lists:
                if head is None:
                    counter += 1
            if counter == k:
                break
            min_val, index = sys.maxsize, 0
            for i, head in enumerate(lists):
                if head is not None and head.val < min_val:
                    min_val = head.val
                    index = i
            result.next = lists[index]
            result = result.next
            lists[index] = lists[index].next
        return dummy.next
