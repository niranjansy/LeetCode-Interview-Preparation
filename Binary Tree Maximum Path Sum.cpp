// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max_path_sum = INT_MIN;
    
    int DFS(TreeNode* node)
    {
        int l_max=0, r_max=0;
        if(node->left != NULL)
            l_max = DFS(node->left);
        if(node->right != NULL)
            r_max = DFS(node->right);
        
        int max_val = max(max(node->val, l_max+node->val), max(r_max+node->val, l_max+r_max+node->val));
        
        if(max_val > max_path_sum)
            max_path_sum = max_val;
        
        return max(node->val, max(l_max+node->val, r_max+node->val));
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
     
        int x = DFS(root);
        
        return max_path_sum;
    }
};