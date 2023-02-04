from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])  # sort by intervals[i][0]
        merged = [False] * len(intervals)
        results = []
        for i in range(len(intervals)):
            if not merged[i]:
                merged[i] = True
                interval = [intervals[i][0], intervals[i][1]]
                for j in range(i + 1, len(intervals)):
                    if not merged[j]:
                        if not (intervals[j][0] > interval[1]):
                            merged[j] = True
                            interval[1] = max(interval[1], intervals[j][1])
                results.append(interval)
        return results
