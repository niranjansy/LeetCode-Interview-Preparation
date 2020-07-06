// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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
    
    int max_BST = 0;
    
    // This function returns {IsBST, sum, max, min} of the sub-tree rooted at node
    vector<int> PostOrderTraversal(TreeNode* node)
    {
        if(node == NULL)
            return {1, 0, 0, 0};
        vector<int> v1 = PostOrderTraversal(node->left);
        vector<int> v2 = PostOrderTraversal(node->right);
        
        int f1 = v1[0]; // Is the left sub-tree a BST?
        int f2 = v2[0]; // Is the right sub-tree a BST?
        int s1 = v1[1]; // Sum of nodes in left sub-tree
        int s2 = v2[1]; // Sum of nodes in right sub-tree
        int M = v1[2]; // Maximum in the left sub-tree
        int m = v2[3]; // Minimum in the right sub-tree
        
        int sum = node->val + s1 + s2;
        
        int IsBST = 0;
        if(f1==1 && f2==1)
        {
            if((node->left == NULL || node->val > M) && (node->right == NULL || node->val < m))
                IsBST = 1;
        }
        
        if(IsBST && sum > max_BST)
            max_BST = sum;
        
        int max, min;
        if(node->left == NULL)
            min = node->val;
        else
            min = v1[3];    // Minimum in the left sub-tree
        
        if(node->right == NULL)
            max = node->val;
        else
            max = v2[2];    // Maximum in the right sub-tree
        
        return {IsBST, sum, max, min};
    }
    
    int maxSumBST(TreeNode* root) {
        vector<int> v = PostOrderTraversal(root);
        
        return max_BST;
        
    }
};