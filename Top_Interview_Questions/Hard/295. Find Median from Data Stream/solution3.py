from heapq import heappush, heappop


class MedianFinder:
    def __init__(self):
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        heappush(self.max_heap, -num)  # python heap is min-heap so add negative to make it max-heap
        heappush(self.min_heap, -heappop(self.max_heap))
        if len(self.min_heap) > len(self.max_heap):
            heappush(self.max_heap, -heappop(self.min_heap))

    def findMedian(self) -> float:
        return (
            (-self.max_heap[0] + self.min_heap[0]) / 2
            if len(self.max_heap) == len(self.min_heap)
            else -self.max_heap[0]
        )
