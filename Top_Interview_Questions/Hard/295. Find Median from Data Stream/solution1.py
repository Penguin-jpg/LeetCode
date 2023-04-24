class MedianFinder:
    def __init__(self):
        self.nums = []
        self.sorted = False

    def addNum(self, num: int) -> None:
        self.sorted = False
        self.nums.append(num)

    def findMedian(self) -> float:
        if not self.sorted:
            self.nums.sort()
        size = len(self.nums)
        return (
            self.nums[size // 2] if size % 2 != 0 else (self.nums[size // 2 - 1] + self.nums[size // 2]) / 2
        )
