// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max=nums[0], cur_max=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            cur_max = max(nums[i], cur_max+nums[i]);
            global_max = max(global_max, cur_max);
        }
        
        return global_max;
        
    
    }
};