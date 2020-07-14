// https://leetcode.com/problems/path-sum-iii/

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
    
    map<int, int> mp;
    int count;
    
    void DFS(TreeNode* node, int pref_sum, int sum)
    {
        pref_sum += node->val;
        if(mp.find(pref_sum - sum) != mp.end())
            count += mp[pref_sum - sum];
        mp[pref_sum]++;
        
        if(node->left != NULL)
            DFS(node->left, pref_sum, sum);
        if(node->right != NULL)
            DFS(node->right, pref_sum, sum);
        
        mp[pref_sum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        
        count = 0;
        mp[0] = 1;
        
        DFS(root, 0, sum);
        
        return count;
    }
};