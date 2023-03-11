from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix, suffix, results = [nums[0]] * n, [nums[-1]] * n, [0] * n
        j, pre, suf = n - 2, 0, 0
        for i in range(1, n):
            prefix[i] = nums[i] * prefix[i - 1]
            suffix[j] = nums[j] * suffix[j + 1]
            j -= 1
        for i in range(n):
            pre = prefix[i - 1] if i > 0 else 1
            suf = suffix[i + 1] if i + 1 < n else 1
            results[i] = pre * suf
        return results
