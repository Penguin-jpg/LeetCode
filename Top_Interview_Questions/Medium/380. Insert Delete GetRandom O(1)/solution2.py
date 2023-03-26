import random


class RandomizedSet:
    def __init__(self):
        self.table = {}
        self.nums = []

    def insert(self, val: int) -> bool:
        if val in self.table:
            return False
        self.nums.append(val)
        self.table[val] = len(self.nums) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.table:
            return False
        last = self.nums[-1]
        self.table[last] = self.table[val]
        self.nums[self.table[last]] = last
        self.nums.pop()
        self.table.pop(val)
        return True

    def getRandom(self) -> int:
        return random.choice(self.nums)  # random select an item from list


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
