// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        long long int c2 = 0, c5 = 0;
        
        long long int i=2;
        while(i <= n)
        {
            long long int c = n/i;
            c2 += c;
            i *= 2;   
        }
        
        i = 5;
        while(i <= n)
        {
            long long int c = n/i;
            c5 += c;
            i *= 5;   
        }
        
        return (int)min(c2, c5);
    }
};