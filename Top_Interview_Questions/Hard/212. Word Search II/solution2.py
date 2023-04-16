from typing import List, Optional


class TrieNode:
    def __init__(self):
        self.end_of_word = False
        self.children = [None] * 26


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for char in word:
            index = ord(char) - ord("a")
            if current.children[index] is None:
                current.children[index] = TrieNode()
            current = current.children[index]
        current.end_of_word = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m, n = len(board), len(board[0])
        results = []
        trie = Trie()
        for word in words:
            trie.insert(word)
        for i in range(m):
            for j in range(n):
                self.dfs(board, i, j, trie.root, "", results)
        return results

    def dfs(
        self,
        board: List[List[str]],
        row: int,
        col: int,
        root: Optional[TrieNode],
        path: str,
        results: List[str],
    ):
        if root.end_of_word:
            root.end_of_word = False
            results.append(path)
        if row < 0 or row >= len(board) or col < 0 or col >= len(board[0]) or board[row][col] == "*":
            return False
        if root.children[ord(board[row][col]) - ord("a")] is not None:
            temp = board[row][col]
            index = ord(temp) - ord("a")
            board[row][col] = "*"
            self.dfs(board, row - 1, col, root.children[index], path + temp, results)
            self.dfs(board, row + 1, col, root.children[index], path + temp, results)
            self.dfs(board, row, col - 1, root.children[index], path + temp, results)
            self.dfs(board, row, col + 1, root.children[index], path + temp, results)
            board[row][col] = temp
