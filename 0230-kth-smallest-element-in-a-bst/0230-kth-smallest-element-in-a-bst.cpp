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
        return findNode(root, k, &cnt);
    }

private:
    int findNode(TreeNode* node, int k, int* cnt) {
        if (node == nullptr) {
            return INT_MIN; // or any suitable default/error value
        }
        
        int left = findNode(node->left, k, cnt);
        if (left != INT_MIN) {
            return left;
        }

        (*cnt)++;
        if (*cnt == k) {
            return node->val;
        }

        return findNode(node->right, k, cnt);
    }
};