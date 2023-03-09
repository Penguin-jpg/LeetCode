class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, node: ListNode):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        previous, current, next = None, node, node.next
        while next is not None:
            previous = current
            current.val = next.val
            current = next
            next = next.next
        previous.next = None
