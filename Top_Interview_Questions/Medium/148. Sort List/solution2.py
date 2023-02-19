from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        slow, fast, temp = head, head, None
        while fast is not None and fast.next is not None:
            temp = slow
            slow = slow.next
            fast = fast.next.next
        temp.next = None
        list1 = self.sortList(head)
        list2 = self.sortList(slow)
        return self.merge(list1, list2)

    def merge(self, list1: Optional[ListNode], list2: Optional[ListNode]):
        dummy = ListNode(0)
        current = dummy
        while list1 is not None and list2 is not None:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        while list1 is not None:
            current.next = list1
            list1 = list1.next
            current = current.next
        while list2 is not None:
            current.next = list2
            list2 = list2.next
            current = current.next
        return dummy.next
