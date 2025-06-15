class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (prev && curr->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }

        if (first && second) {
            swap(first->val, second->val);
        }
    }
};