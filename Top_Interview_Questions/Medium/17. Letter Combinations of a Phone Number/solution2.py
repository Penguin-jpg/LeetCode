from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        table = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }
        results = []
        self.find_combinations(digits, table, 0, "", results)
        return results

    def find_combinations(self, digits: str, table: dict, index: int, combination: str, results: List[str]):
        if index >= len(digits):
            results.append(combination)
            return
        letters = table[digits[index]]
        for j in range(0, len(letters)):
            self.find_combinations(digits, table, index + 1, combination + letters[j], results)
