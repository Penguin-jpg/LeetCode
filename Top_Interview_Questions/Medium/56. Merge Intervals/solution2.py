from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])  # sort by intervals[i][0]
        results = [intervals[0]]
        for i in range(1, len(intervals)):
            if results[-1][1] >= intervals[i][0]:
                results[-1][1] = max(results[-1][1], intervals[i][1])
            else:
                results.append(intervals[i])
        return results
