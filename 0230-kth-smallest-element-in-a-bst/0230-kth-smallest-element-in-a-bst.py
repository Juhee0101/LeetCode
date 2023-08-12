# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self) -> None:
        self.count = 0

    def __kthSmallestHelp(self, curNode: TreeNode, k:int) -> int:
        if not curNode:
            return 0
        
        # if curNode.left:
        leftResult = self.__kthSmallestHelp(curNode.left, k)
        if leftResult:
            return leftResult

        self.count += 1
        if self.count == k:
            return curNode.val

        # if curNode.right:
        return self.__kthSmallestHelp(curNode.right, k)          

    def kthSmallest(self, root: TreeNode, k: int) -> int:
        return self.__kthSmallestHelp(root, k)