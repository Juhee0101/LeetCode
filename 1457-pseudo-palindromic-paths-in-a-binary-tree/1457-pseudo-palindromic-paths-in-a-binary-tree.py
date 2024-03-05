# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __helpFunc(self, curNode: TreeNode, strCnt: dict) -> int:
        # 현재 노드가 없다면, 카운트를 증가시키지 않고 0을 반환합니다.
        if not curNode:
            return 0

        # 노드 값의 카운트를 증가시키거나 새로운 값으로 초기화합니다.
        strCnt[curNode.val] = strCnt.get(curNode.val, 0) + 1

        # 리프 노드에 도달했을 때, 팰린드롬 가능성을 확인합니다.
        if curNode.left is None and curNode.right is None:
            numOdd = sum(1 for val in strCnt.values() if val % 2 == 1)
            cnt = 1 if numOdd <= 1 else 0
        else:
            # 리프 노드가 아니라면, 왼쪽과 오른쪽 자식을 계속 탐색합니다.
            cnt = self.__helpFunc(curNode.left, strCnt) + self.__helpFunc(curNode.right, strCnt)
        
        # 자식 노드에 대한 재귀 호출이 완료된 후 현재 노드의 값을 감소시킵니다.
        strCnt[curNode.val] -= 1
        if strCnt[curNode.val] == 0:
            del strCnt[curNode.val]
        
        return cnt
            
    def pseudoPalindromicPaths(self, root: TreeNode) -> int:
        strCnt = dict()
        return self.__helpFunc(root, strCnt)