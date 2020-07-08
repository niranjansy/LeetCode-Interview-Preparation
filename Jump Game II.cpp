// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jump_from(n, -1);
        
        int max_reach = 0;
        for(int i=0; i<(n-1); i++)
        {
            for(int j=max_reach+1; j<=(i+nums[i]) && j<n; j++)
                jump_from[j] = i;
            if((i+nums[i]) > max_reach)
                max_reach = i + nums[i];
        }
        
        int i = n-1;
        int count = 0;
        while(i > 0)
        {
            i = jump_from[i];
            count++;
        }
        return count;
    }
};