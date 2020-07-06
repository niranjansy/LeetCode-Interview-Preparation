// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        for(int i=0; i<(n-1); i++)
        {
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        }
        
        for(int l=2; l<n; l++)
        {
            for(int i=0; i<n-l; i++)
            {
                int j = i+l;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        
        return dp[0][n-1];
    }
};