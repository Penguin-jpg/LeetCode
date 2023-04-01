from typing import List, Optional


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        return self.merge(lists, 0, len(lists) - 1)

    def merge(self, lists: List[Optional[ListNode]], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return lists[left]
        mid = int((left + right) / 2)
        list1 = self.merge(lists, left, mid)
        list2 = self.merge(lists, mid + 1, right)
        return self.merge_two_lists(list1, list2)

    def merge_two_lists(self, left: Optional[ListNode], right: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        result = dummy
        while left is not None and right is not None:
            if left.val < right.val:
                result.next = left
                left = left.next
            else:
                result.next = right
                right = right.next
            result = result.next
        result.next = left if left is not None else right
        return dummy.next
