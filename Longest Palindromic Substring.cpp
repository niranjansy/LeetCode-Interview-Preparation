// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[1000][1000] = {0};
        
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        for(int i=0; i<(n-1); i++)
        {
            if(s[i] == s[i+1])
                dp[i][i+1] = 1;
            else
                dp[i][i+1] = 0;
        }
        
        for(int l=3; l<=n; l++)
        {
            for(int i=0; i<=(n-l); i++)
            {
                int j = i + l - 1;
                if(dp[i+1][j-1] == 1 && s[i] == s[j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
        
        string res = "";
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(dp[i][j] == 1 && (j-i+1)>res.size())
                    res = s.substr(i, j-i+1);
            }
        }
        
        return res;
    }
};