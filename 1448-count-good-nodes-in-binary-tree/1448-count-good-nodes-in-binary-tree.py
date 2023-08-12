# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self) -> None:
        self.goodNum = 0

    def __goodNodesHelp(self, curNode: TreeNode, maxVal: int) -> None:
        if not curNode:
            return
        
        if curNode.val >= maxVal:
            maxVal = curNode.val
            self.goodNum += 1

        self.__goodNodesHelp(curNode.left, maxVal)
        self.__goodNodesHelp(curNode.right, maxVal)

    def goodNodes(self, root: TreeNode) -> int:
        self.__goodNodesHelp(root, root.val)
        return self.goodNum
        