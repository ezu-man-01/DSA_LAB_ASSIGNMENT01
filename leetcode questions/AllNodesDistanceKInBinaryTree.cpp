class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        buildParentMap(root, nullptr, parent_map);
        
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);
        vector<int> result;
        
        while (!q.empty()) {
            auto [node, distance] = q.front();
            q.pop();
            
            if (distance == k) {
                result.push_back(node->val);
            } else if (distance < k) {
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push({node->left, distance + 1});
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push({node->right, distance + 1});
                }
                TreeNode* parent = parent_map[node];
                if (parent && visited.find(parent) == visited.end()) {
                    visited.insert(parent);
                    q.push({parent, distance + 1});
                }
            }
        }
        
        return result;
    }
    
private:
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        if (!node) {
            return;
        }
        parent_map[node] = parent;
        buildParentMap(node->left, node, parent_map);
        buildParentMap(node->right, node, parent_map);
    }
};