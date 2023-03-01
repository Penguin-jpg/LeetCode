from typing import List
from enum import Enum


class Color(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)
        return not self.has_cycle(graph)

    def has_cylce_helper(self, graph: List[List[int]], node: int, color: List[Color]) -> bool:
        if color[node] == Color.GRAY:
            return True
        elif color[node] == Color.BLACK:
            return False
        color[node] = Color.GRAY
        for i in graph[node]:
            if self.has_cylce_helper(graph, i, color):
                return True
        color[node] = Color.BLACK
        return False

    def has_cycle(self, graph: List[List[int]]) -> bool:
        color = [Color.WHITE for _ in range(len(graph))]
        for i in range(len(graph)):
            if self.has_cylce_helper(graph, i, color):
                return True
        return False
