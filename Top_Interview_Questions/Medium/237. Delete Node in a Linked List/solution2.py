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
        self.get_next_val(node)

    def get_next_val(self, node: ListNode):
        if node.next.next is None:
            val = node.val
            node.val = node.next.val
            node.next = None
            return val
        val = node.val
        node.val = self.get_next_val(node.next)
        return val
