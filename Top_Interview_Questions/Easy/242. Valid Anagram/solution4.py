from collections import Counter

# python 專屬解法，直接用 Counter 算出現頻率


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
