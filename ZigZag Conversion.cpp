// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = s.size();        
        int k = numRows;
        if(k == 1)
            return s;
        
        for(int j=0; j<n; j += 2*(k-1))
            res.push_back(s[j]);
        for(int i=2; i<k; i++)
        {
            for(int c=0, j=i-1; j<n; c++)
            {
                res.push_back(s[j]);
                if(c % 2 == 0)
                    j += (2*(k-i));
                else
                    j += (2*(i-1));
            }
        }
        if(k <= n)
        {
            for(int j=k-1; j<n; j += 2*(k-1))
                res.push_back(s[j]);
        }
        
        
        return res;
    }
};