// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pref_sums[n+1];
        pref_sums[0] = 0;
        
        for(int i=0; i<n; i++)
        {
            pref_sums[i+1] = pref_sums[i] + nums[i];
        }
        
        map<int, vector<int>> mp;
        
        for(int i=0; i<(n+1); i++)
        {
            mp[pref_sums[i]].push_back(i);
        }
        
        int count = 0;
        
        for(int i=1; i<(n+1); i++)
        {
            int diff = pref_sums[i] - k;
            if(mp.find(diff) != mp.end())
            {
                for(int j=0; j<mp[diff].size(); j++)
                {
                    if(mp[diff][j] < i)
                        count++;
                }
            }
        }
        
        return count;
    }
};