class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        return self.get_max_length(s, 0, len(s), k)

    def get_max_length(self, s: str, left: int, right: int, k: int) -> int:
        if right - left < k:
            return 0
        table = [0] * 26
        for i in range(left, right):
            table[ord(s[i]) - ord("a")] += 1
        for split in range(left, right):
            if table[ord(s[split]) - ord("a")] < k:
                return max(
                    self.get_max_length(s, left, split, k), self.get_max_length(s, split + 1, right, k)
                )
        return right - left
