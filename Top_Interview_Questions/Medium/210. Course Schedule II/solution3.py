from typing import List
from enum import Enum


class Color(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)
        return self.topological_sort(graph)

    def has_cycle(self, graph: List[List[int]], node: int, color: List[Color], path: List[int]) -> bool:
        if color[node] == Color.GRAY:
            return True
        elif color[node] == Color.BLACK:
            return False
        color[node] = Color.GRAY
        for i in graph[node]:
            if self.has_cycle(graph, i, color, path):
                return True
        color[node] = Color.BLACK
        path.append(node)
        return False

    def topological_sort(self, graph: List[List[int]]) -> List[int]:
        color = [Color.WHITE for _ in range(len(graph))]
        path = []
        for i in range(len(graph)):
            if self.has_cycle(graph, i, color, path):
                return []
        path.reverse()
        return path
