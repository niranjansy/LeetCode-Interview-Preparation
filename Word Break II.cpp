// https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    
    vector<string> BuildResult(vector<int> Check[], int len, string S)
    {
        if(len == 0)
            return {};
        
        vector<string> V;
        for(int i=0; i<Check[len].size(); i++)
        {
            int k = Check[len][i];
            string R = S.substr(len-k, k);
            
            vector<string> V1 = BuildResult(Check, len-k, S);
            
            for(int j=0; j<V1.size(); j++)
            {
                V.push_back(V1[j] + " " + R);
            }
            if(V1.size() == 0)
                V.push_back(R);
        }
        
        return V;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int N = wordDict.size();
        int len = s.size();
        
        vector<int> Check[1000];
        Check[0] = {0};
        
        for(int i=1; i<=len; i++)
        {
            if(Check[i-1].size() > 0)
            {
                for(int j=0; j<N; j++)
                {
                    int l = wordDict[j].size();
                    if(l <= (len-i+1) &&  wordDict[j] == s.substr(i-1, l))
                        Check[i+l-1].push_back(l);
                }
            }
        }
        
        vector<string> res = BuildResult(Check, len, s);
        
        return res;
    }
};