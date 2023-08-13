# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __buildTreeHelp(self, preorder: list[int], inorder: list[int]) -> TreeNode:
        if len(inorder)==0:
            return
        elif len(inorder)==1:
            return TreeNode(inorder[0])
        
        for node in preorder:
            root = TreeNode()
        
        root = TreeNode(preorder[0])
        rootIdx = inorder.index(preorder[0])
        root.left = self.__buildTreeHelp(preorder[1:], inorder[:rootIdx])
        root.right = self.__buildTreeHelp(preorder[rootIdx+1:], inorder[rootIdx+1:])
        return root

    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode:
        return self.__buildTreeHelp(preorder, inorder)
        