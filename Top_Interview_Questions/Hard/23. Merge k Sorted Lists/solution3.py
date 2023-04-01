from typing import List, Optional
from heapq import heappop, heappush


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    # this is how you define __lt__ in class
    def __lt__(self, other):
        return -self.val < -other.val


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        previous, max_heap = None, []
        # since we want to directly store node in heap, not just val, we have to
        # define __lt__ or __gt__ for ListNode. but we cannot do this because
        # leetcode does not accept it. we will use setattr and lambda to do this
        setattr(ListNode, "__lt__", lambda self, other: -self.val < -other.val)
        for head in lists:
            while head is not None:
                heappush(max_heap, head)
                head = head.next
        while len(max_heap) != 0:
            current = heappop(max_heap)
            current.next = previous
            previous = current
        return previous
