class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int current_num) {
        if (!node) return 0;
        current_num = current_num * 10 + node->val;
        if (!node->left && !node->right) {
            return current_num;
        }
        return dfs(node->left, current_num) + dfs(node->right, current_num);
    }
};