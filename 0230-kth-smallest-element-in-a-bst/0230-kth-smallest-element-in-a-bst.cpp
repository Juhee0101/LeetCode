/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res;
        findNode(root, k, &cnt, &res);
        return res;
    }
private:
    void findNode(TreeNode* node, int k, int *cnt, int *res) {
        if (node == nullptr) {
            return;
        }

        findNode(node->left, k, cnt, res);
        (*cnt)++;
        if (*cnt == k) {
            *res = node->val;
            return;
        }
        findNode(node->right, k, cnt, res);
        return;
    }
};