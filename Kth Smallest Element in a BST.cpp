// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int count=0, res, flag=0;
    
    void InOrder(TreeNode* root, int k)
    {
        if(root == NULL || flag==1)
            return;
        InOrder(root->left, k);
        count++;
        if(k == count)
        {
            res = root->val;
            flag = 1;
        }
           
        InOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        InOrder(root, k);
        
        return res;
    }
};