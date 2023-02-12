from typing import Optional
from collections import deque


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
        nodes = deque([root])
        size, previous, current = len(nodes), None, None
        while len(nodes) != 0:
            for _ in range(size):
                previous = current
                current = nodes.popleft()
                if current.right is not None:
                    nodes.append(current.right)
                if current.left is not None:
                    nodes.append(current.left)
                current.next = previous
            size = len(nodes)
            current = None
        return root
