import sys

# 跑起來有錯，但檢查不出錯在哪
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.counter = 1
        self.cache = {}

    def get(self, key: int) -> int:
        value = self.cache[key][0] if key in self.cache else -1
        if value != -1:
            self.cache[key][1] = self.counter
            self.counter += 1
        return value

    def put(self, key: int, value: int) -> None:
        if key not in self.cache and len(self.cache) == self.capacity:
            least_used, min_value = -1, sys.maxsize
            for key, pair in self.cache.items():
                if pair[1] < min_value:
                    least_used = key
                    min_value = pair[1]
            self.cache.pop(least_used)
        self.cache[key] = [value, self.counter]
        self.counter += 1
