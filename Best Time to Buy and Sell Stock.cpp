// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;

        int cur_min = prices[0];
        int max_profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            int diff = prices[i] - cur_min;
            if (diff > max_profit)
                max_profit = diff;
            cur_min = min(cur_min, prices[i]);
        }
        
        return max_profit;
    }
};