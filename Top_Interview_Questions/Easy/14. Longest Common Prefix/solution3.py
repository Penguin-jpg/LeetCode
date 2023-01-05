from typing import List

# 參考解答: 透過 * 將 strs 內每個字串取出，用 zip 把每個字串的字元包成多個
# tuple，若 tuple 內的字元都一樣，則轉成 set 後的大小應為 1


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        for char_tuple in zip(*strs):
            if len(set(char_tuple)) == 1:
                prefix += char_tuple[0]
            else:
                break
        return prefix
