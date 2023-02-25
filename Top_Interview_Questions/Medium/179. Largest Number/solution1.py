from typing import List
from functools import cmp_to_key


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        strs = [str(num) for num in nums]
        # the concept of cmp is to define what are a>b, a<b, and a==b
        # we define a+b>b+a as a>b -> return 1
        # a+b<b+a as a<b -> return -1
        # a+b==b+a as a==b -> return 0
        strs.sort(
            key=cmp_to_key(lambda a, b: 1 if a + b > b + a else -1 if a + b < b + a else 0), reverse=True
        )
        result = str("".join(strs))
        while result[0] == "0" and len(result) > 1:
            result = result[1:]
        return result
