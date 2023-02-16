from typing import Optional


class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if head is None:
            return head
        table, current = {}, head
        while current is not None:
            table[current] = Node(current.val)
            current = current.next
        current = head
        while current is not None:
            table[current].next = table[current.next] if current.next is not None else None
            table[current].random = table[current.random] if current.random is not None else None
            current = current.next
        return table[head]
