# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root, maximum = float('inf'), minimum = float('-inf')):
        if not root:
            return True
        
        if not minimum < root.val < maximum:
            return False
        
        return self.isValidBST(root.left, root.val, minimum) and self.isValidBST(root.right, maximum, root.val)
    
        