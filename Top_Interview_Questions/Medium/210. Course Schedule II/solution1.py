from typing import List
from collections import deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)
        return self.topological_sort(graph)

    def topological_sort(self, graph: List[List[int]]) -> List[int]:
        in_degree = [0 for _ in range(len(graph))]
        nodes = deque()
        path = []
        for adj in graph:
            for i in adj:
                in_degree[i] += 1
        for i, degree in enumerate(in_degree):
            if degree == 0:
                nodes.append(i)
        counter = 0
        while len(nodes) != 0:
            node = nodes.popleft()
            path.append(node)
            counter += 1
            for i in graph[node]:
                in_degree[i] -= 1
                if in_degree[i] == 0:
                    nodes.append(i)
        return path if counter == len(graph) else []
