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
        random_pointers, indices, new_nodes = {}, {}, []
        dummy = Node(0)
        new_head = dummy
        i = 0
        while head is not None:
            new_head.next = Node(head.val)
            new_head = new_head.next
            new_nodes.append(new_head)
            random_pointers[new_head] = head.random
            indices[head] = i
            head = head.next
            i += 1
        new_head = dummy.next
        while new_head is not None:
            if random_pointers[new_head] is not None:
                index = indices[random_pointers[new_head]]
                new_head.random = new_nodes[index]
            else:
                new_head.random = None
            new_head = new_head.next
        return dummy.next
