// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    vector<int> nodes;
    
    void Traversal(TreeNode* node)
    {
        if(node==NULL)
            return;
        nodes.push_back(node->val);
        Traversal(node->left);
        Traversal(node->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        Traversal(root1);
        Traversal(root2);
        
        sort(nodes.begin(), nodes.end());
        
        return nodes;
    }
};