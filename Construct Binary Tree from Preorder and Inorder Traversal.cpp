// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* BuildTreeRecursive(vector<int> preorder, int lp, int rp, vector<int> inorder, int li, int ri)
    {
        if(lp > rp || li > ri)
            return NULL;
        
        TreeNode* root = new TreeNode;
        root->val = preorder[lp];
        int i;
        for(i=li; i<=ri; i++)
        {
            if(inorder[i] == preorder[lp])
                break;
        }
        
        root->left = BuildTreeRecursive(preorder, lp+1, lp+i-li , inorder, li, i-1);
        root->right = BuildTreeRecursive(preorder, lp+i-li+1, rp, inorder, i+1, ri);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return BuildTreeRecursive(preorder, 0, n-1, inorder, 0, n-1);
    }
    
};