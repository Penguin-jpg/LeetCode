from typing import List, Optional
import sys


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        result = []
        self.inorder(root, result)
        return ",".join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        values = self.split_by_comma(data)
        index = [0]
        return self.build_tree(values, index)

    # since python cannot modify str in function, use this instead
    def inorder(self, root: Optional[TreeNode], result: List[str]):
        if root is None:
            result.append(" ")
            return
        result.append(str(root.val))
        self.inorder(root.left, result)
        self.inorder(root.right, result)

    def split_by_comma(self, string: str):
        values = []
        start = 0
        while True:
            lastPos = string.find(",", start)
            if lastPos == -1:
                break
            val = string[start:lastPos]
            if val == " ":
                values.append(-sys.maxsize)
            else:
                values.append(int(val))
            start = lastPos + 1
        return values

    def build_tree(self, values: List[int], index: List[int]):
        if index[0] >= len(values) or values[index[0]] == -sys.maxsize:
            return None
        root = TreeNode(values[index[0]])
        index[0] += 1
        root.left = self.build_tree(values, index)
        index[0] += 1
        root.right = self.build_tree(values, index)
        return root


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
