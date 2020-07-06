// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.insert(prices.end(), 0);
        int n = prices.size();
        int profit = 0;
        bool bought = 0;
        for(int i=0; i<prices.size(); i++)
        {
            if((i+1)<n && prices[i] < prices[i+1] && bought == 0)
            {
                profit -= prices[i];
                bought = 1;
            }
                
            if((i+1)<n && prices[i] > prices[i+1] && bought == 1)
            {
                profit += prices[i];
                bought = 0;
            }
                
        }
        return profit;
        
        
    }
};