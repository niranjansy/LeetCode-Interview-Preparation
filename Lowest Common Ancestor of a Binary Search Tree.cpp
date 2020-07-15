// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        int p_val = p->val;
        int q_val = q->val;
        
        TreeNode* node = root;
        while(true)
        {
            int val = node->val;
            if(p_val < val && q_val < val)
                node = node->left;
            else if(p_val > val && q_val > val)
                node = node->right;
            else 
                break;
        }
        
        return node;
        
    }
};