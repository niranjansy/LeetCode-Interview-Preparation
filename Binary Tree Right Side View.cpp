// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> Q;
        if(root == NULL)
            return {};
        
        vector<int> res;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            if(node != NULL && node->left != NULL)
                Q.push(node->left);
            if(node != NULL && node->right != NULL)
                Q.push(node->right);
            
            if(Q.front() == NULL)
            {
                res.push_back(node->val);
                Q.push(NULL);
                Q.pop();
            }
        }
        
        return res;
    }
};