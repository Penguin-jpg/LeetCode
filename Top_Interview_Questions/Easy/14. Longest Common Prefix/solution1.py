from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        for i in range(len(strs[0])):
            for j in range(1, len(strs)):
                if i >= len(strs[j - 1]) or i >= len(strs[j]) or strs[j - 1][i] != strs[j][i]:
                    return prefix
            prefix += strs[0][i]
        return prefix
