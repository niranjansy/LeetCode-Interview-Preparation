// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = wordDict.size();
        int len = s.size();
        sort(wordDict.begin(), wordDict.end());
        
        bool Check[1000] = {0};
        Check[0] = 1;
        
        for(int i=1; i<=len; i++)
        {
            if(Check[i-1] == 1)
            {
                for(int j=0; j<N; j++)
                {
                    int l = wordDict[j].size();
                    if(l <= (len-i+1) &&  wordDict[j] == s.substr(i-1, l))
                        Check[i+l-1] = 1;
                }
            }
        }
        
        if(Check[len] == 1)
            return true;
        else
            return false;
        
    }
};