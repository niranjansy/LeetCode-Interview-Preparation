// https://leetcode.com/problems/integer-replacement/

class Solution {
public:
    long long int HighestPowerOf2(long long int n)
    {
        return n&(~(n-1));
    }
    
    int integerReplacement(long long int n) {
        int count = 0;
        
        while(n > 1)
        {
            if(n == 3)
            {
                count += 2;
                n = 1;
            }
                
            else if(n%2 == 0)
            {
                n /= 2;
                count++;
            }
            else
            {
                long long int p1 = HighestPowerOf2(n+1);
                long long int p2 = HighestPowerOf2(n-1); 
                if(p1>p2)
                    n = n+1;
                else
                    n = n-1;
                count++;
            }
        }
        
        return count;
    }
};