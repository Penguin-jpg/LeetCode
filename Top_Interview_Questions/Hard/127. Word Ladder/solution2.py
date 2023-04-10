from typing import List
from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0
        q = deque([beginWord])
        words.add(beginWord)
        counter = 1
        while len(q) > 0:
            size = len(q)
            for _ in range(size):
                current = q.popleft()
                if current == endWord:
                    return counter
                for j in range(len(current)):
                    temp = current
                    for k in range(26):
                        current = current[:j] + chr(ord("a") + k) + current[j + 1 :]
                        if current in words:
                            q.append(current)
                            words.remove(current)
                    current = temp
            counter += 1
        return 0
