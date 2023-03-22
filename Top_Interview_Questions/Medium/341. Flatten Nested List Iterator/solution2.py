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
        self.nests = nestedList
        self.nests.reverse()  # reverse the order so we can use it like stack

    def next(self) -> int:
        return self.nests.pop().getInteger()

    def hasNext(self) -> bool:
        while len(self.nests) != 0:
            if self.nests[-1].isInteger():
                return True
            nested_list = self.nests.pop().getList()
            nested_list.reverse()
            for nest in nested_list:
                self.nests.append(nest)
        return False


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
