from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)
        return not self.has_cycle(graph)

    def has_cylce_helper(
        self, graph: List[List[int]], node: int, visited: List[bool], in_stack: List[bool]
    ) -> bool:
        if in_stack[node]:
            return True
        elif visited[node]:
            return False
        visited[node] = True
        in_stack[node] = True
        for i in graph[node]:
            if self.has_cylce_helper(graph, i, visited, in_stack):
                return True
        in_stack[node] = False
        return False

    def has_cycle(self, graph: List[List[int]]) -> bool:
        visited = [False for _ in range(len(graph))]
        in_stack = [False for _ in range(len(graph))]
        for i in range(len(graph)):
            if self.has_cylce_helper(graph, i, visited, in_stack):
                return True
        return False
