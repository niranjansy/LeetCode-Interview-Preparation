// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
        long long int reverse(long long int x) {
        int neg = 0;
        if(x < 0)
        {
            neg = 1;
            x *= -1;;
        }
        long long int rev=0;
        while(x > 0)
        {
            int d = x % 10;
            x /= 10;
            rev = rev*10 + d;
        }
        if(neg)
            rev *= -1;
            
        if(rev < (-1*pow(2, 31)) || rev > (pow(2,31)-1))
            rev = 0;
        return rev;
    }
};