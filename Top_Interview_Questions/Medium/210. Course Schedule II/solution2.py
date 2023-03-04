from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)
        return self.topological_sort(graph)

    def has_cycle(
        self, graph: List[List[int]], node: int, visited: List[bool], in_stack: List[bool], path: List[int]
    ) -> bool:
        if in_stack[node]:
            return True
        elif visited[node]:
            return False
        visited[node], in_stack[node] = True, True
        for i in graph[node]:
            if self.has_cycle(graph, i, visited, in_stack, path):
                return True
        in_stack[node] = False
        path.append(node)
        return False

    def topological_sort(self, graph: List[List[int]]) -> List[int]:
        visited = [False for _ in range(len(graph))]
        in_stack = [False for _ in range(len(graph))]
        path = []
        for i in range(len(graph)):
            if self.has_cycle(graph, i, visited, in_stack, path):
                return []
        path.reverse()
        return path
