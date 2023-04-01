from typing import List, Optional
from functools import cmp_to_key


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        previous, nodes = None, []
        for head in lists:
            while head is not None:
                nodes.append(head)
                head = head.next
        nodes.sort(key=cmp_to_key(lambda a, b: 1 if a.val < b.val else -1 if a.val > b.val else 0))
        for node in nodes:
            node.next = previous
            previous = node
        return previous
