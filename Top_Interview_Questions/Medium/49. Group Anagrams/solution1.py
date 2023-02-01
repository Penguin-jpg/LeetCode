from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for i in range(len(strs)):
            sort_str = "".join(sorted(strs[i]))
            if sort_str not in groups:
                groups[sort_str] = []
            groups[sort_str].append(strs[i])
        return [group for group in groups.values()]
