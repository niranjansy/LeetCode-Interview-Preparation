// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        
        string common_prefix = strs[0];
        for(int i=1; i<n; i++)
        {
            int j = 0;
            while(j<common_prefix.size() && j<strs[i].size())
            {
                if(common_prefix[j] != strs[i][j])
                    break;
                j++;
            }
            common_prefix = common_prefix.substr(0, j);
        }
        
        return common_prefix;
    }
};