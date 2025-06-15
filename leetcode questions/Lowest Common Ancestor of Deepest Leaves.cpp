class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }

    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else if (left.second < right.second) {
            return {right.first, right.second + 1};
        } else {
            return {node, left.second + 1};
        }
    }
};