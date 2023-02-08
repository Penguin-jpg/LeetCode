from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        nums = []
        self.inorder(root, nums)
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                return False
        return True

    def inorder(self, root: Optional[TreeNode], nums: List[int]):
        if root is None:
            return
        self.inorder(root.left, nums)
        nums.append(root.val)
        self.inorder(root.right, nums)
