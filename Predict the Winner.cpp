// https://leetcode.com/problems/predict-the-winner/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int pref_sum[n+1];
        pref_sum[0] = 0;
        for(int i=1; i<=n; i++)
            pref_sum[i] = pref_sum[i-1] + nums[i-1];
        
        int DP[n][n][2];
        // DP[i][j][0] indicates the score that can be gained on subarray [i..j], on starting first
        // DP[i][j][1] indicates the score that can be gained on subarray [i..j], on starting second
        // DP[i][j][0] + DP[i][j][1] = Sum of subarray[i..j] = pref_sum[j+1] - pref_sum[i]
        
        for(int i=0; i<n; i++)
        {
            DP[i][i][0] = nums[i];
            DP[i][i][1] = 0;
        }
        
        for(int s=1; s<n; s++)
        {
            for(int i=0; i<(n-s); i++)
            {
                int j = i+s;
                DP[i][j][0] = max(nums[i] + DP[i+1][j][1], nums[j] + DP[i][j-1][1]);
                DP[i][j][1] = (pref_sum[j+1] - pref_sum[i]) - DP[i][j][0];
            }
        }
        
        if(DP[0][n-1][0] >= DP[0][n-1][1])
            return true;
        return false;
    }
};