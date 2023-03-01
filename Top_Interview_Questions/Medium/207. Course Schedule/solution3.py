from typing import List
from collections import deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)
        return not self.has_cycle(graph, numCourses)

    def has_cycle(self, graph: List[List[int]], n: int) -> bool:
        in_degree = [0 for _ in range(n)]
        nodes = deque()
        counter = 0
        for adj in graph:
            for node in adj:
                in_degree[node] += 1
        for i in range(n):
            if in_degree[i] == 0:
                nodes.append(i)
        while len(nodes) != 0:
            node = nodes.popleft()
            counter += 1
            for i in graph[node]:
                in_degree[i] -= 1
                if in_degree[i] == 0:
                    nodes.append(i)
        return counter != n
