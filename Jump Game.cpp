// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reach = 0;
        
        for(int i=0; i<n; i++)
        {
            if(max_reach >= i && (i+nums[i]) > max_reach)
                max_reach = i + nums[i];
        }
        
        return (max_reach >= (n-1));
    }
};