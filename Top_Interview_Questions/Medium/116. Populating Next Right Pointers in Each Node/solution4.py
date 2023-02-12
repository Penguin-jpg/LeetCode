from typing import Optional


class Node:
    def __init__(self, val: int = 0, left: "Node" = None, right: "Node" = None, next: "Node" = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        if root is None:
            return root
        head = root
        while root is not None:
            current = root
            while current is not None:
                if current.left is not None:
                    current.left.next = current.right
                    if current.next is not None:
                        current.right.next = current.next.left
                current = current.next
            root = root.left
        return head
