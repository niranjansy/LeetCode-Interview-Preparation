// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> paths;
    vector<int> path;
    int path_sum;
    
    void DFS(TreeNode* node, int sum)
    {
        path.push_back(node->val);
        path_sum += node->val;
        
        if(node->left != NULL)
            DFS(node->left, sum);
            
        if(node->right != NULL)
            DFS(node->right, sum);
        
        if(node->left == NULL && node->right == NULL)
        {
            if(path_sum == sum)
                paths.push_back(path);
        }
        
        path.erase(path.end() - 1);
        path_sum -= node->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return {};
        
        path_sum = 0;
        
        DFS(root, sum);
        
        return paths;
        
    }
};