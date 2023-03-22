from typing import List

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
class NestedInteger:
    def isInteger(self) -> bool:
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        """
        pass

    def getInteger(self) -> int:
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        """
        pass

    def getList(self) -> List["NestedInteger"]:
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        """
        pass


class NestedIterator:
    def __init__(self, nestedList: List[NestedInteger]):
        self.nums = []
        self.index = 0
        self.flatten(nestedList)

    def flatten(self, nestedList: List[NestedInteger]):
        for nested in nestedList:
            if nested.isInteger():
                self.nums.append(nested.getInteger())
            else:
                self.flatten(nested.getList())

    def next(self) -> int:
        result = self.nums[self.index]
        self.index += 1
        return result

    def hasNext(self) -> bool:
        return self.index < len(self.nums)


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
