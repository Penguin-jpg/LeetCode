from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inorder_indices = {value: index for index, value in enumerate(inorder)}
        self.preorder_left = 0
        return self.build(preorder, inorder, inorder_indices, 0, len(inorder) - 1)

    def build(
        self,
        preorder: List[int],
        inorder: List[int],
        inorder_indices: dict,
        inorder_left,
        inorder_right,
    ):
        if inorder_left > inorder_right:
            return None
        root = TreeNode(preorder[self.preorder_left])
        root_index = inorder_indices[root.val]
        self.preorder_left += 1
        root.left = self.build(preorder, inorder, inorder_indices, inorder_left, root_index - 1)
        root.right = self.build(preorder, inorder, inorder_indices, root_index + 1, inorder_right)
        return root
