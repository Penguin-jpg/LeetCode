# 因為 python 沒有提供內建的 doubly linked list，所以要自己寫一個
# 程式碼來源如下：
# https://leetcode.com/problems/lru-cache/solutions/352295/python3-doubly-linked-list-and-dictionary/


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.head = Node(0, 0)  # head dummy node
        self.tail = Node(-1, -1)  # tail dummy node
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self.remove_from_list(node)  # remove from original position
            self.push_front(node)  # push to front as the most recently used element
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.remove_from_list(node)
            self.push_front(node)
            node.value = value
        else:
            if len(self.cache) == self.capacity:
                self.pop_back()  # remove the least recently used element
            node = Node(key, value)
            self.cache[key] = node
            self.push_front(node)

    # remove node from any position
    def remove_from_list(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev

    # remove the node next to head
    def push_front(self, node: Node):
        head_next = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = head_next
        head_next.prev = node

    # remove the node next to tail
    def pop_back(self):
        if len(self.cache) == 0:
            return
        tail_node = self.tail.prev
        self.cache.pop(tail_node.key)  # remove it from cache
        self.remove_from_list(tail_node)
