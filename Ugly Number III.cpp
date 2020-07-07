// https://leetcode.com/problems/ugly-number-iii/

#define ll long long int

class Solution {
public:
    
    ll GCD(ll a, ll b)
    {
        if(b == 0)
            return a;
        return GCD(b, a%b);
    }
    
    ll LCM(ll a, ll b)
    {  
        return (a*b)/GCD(a, b);
    }
    
    ll BinarySearch(ll n, ll a, ll b, ll c)
    {
        ll found = 0;
        ll l = 1, r = n;
        
        while(l <= r)
        {
            ll m = (l + r)/2;
            // Checking if the m'th multiple of 'a' is the n'th ugly number
            ll val = m * a;
            ll count = m + (val/b)  + (val/c) - (val/LCM(a,b)) - (val/LCM(a,c)) - (val/LCM(b,c)) + (val/LCM(a, LCM(b,c)));
            if(count == n)
                return val;
            else if(count < n)
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        // Searching among the multiples of a
        ll res = BinarySearch((ll)n, (ll)a, (ll)b, (ll)c);
        if(res != -1)
            return res;
        
        // Searching among the multiples of b
        res = BinarySearch(n, b, a, c);
        if(res != -1)
            return res;
        
        // Searching among the multiples of c
        res = BinarySearch(n, c, a, b);
        return (int)res;
        
    }
};