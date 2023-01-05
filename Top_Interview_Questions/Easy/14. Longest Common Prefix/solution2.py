from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        strs = sorted(strs)
        for i in range(len(strs[0])):
            if strs[0][i] == strs[-1][i]:
                prefix += strs[0][i]
            else:
                break
        return prefix
