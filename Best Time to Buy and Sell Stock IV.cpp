// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        prices.insert(prices.end(), 0);
        int n = prices.size();
        int count = 0;
        int profit = 0;
        bool have = 0;
        vector<pair<int, int>> T;
        
        // Finding the maximum profit without any restrictions on the number of transactions
        for(int i=0; i<(n-1); i++)
        {
            if(prices[i+1] > prices[i] && !have)
            {
                profit -= prices[i];
                T.push_back(make_pair(prices[i], 0));
                have = 1;
            }
            if(prices[i+1]<prices[i] && have)
            {
                profit += prices[i];
                T.back().second = prices[i];
                have = 0;
            }
        }
        
        count = T.size();
        if(k < count)
        {
            int diff = count - k;
            // Removing or merging transactions to reduce their number to k
            while(diff)
            {
                int min = T[0].second - T[0].first;
                int type = 0;
                int pos = 0;
                
                // Finding the best transaction to remove
                // type 0 indicates removing a transaction, type1 indicates merging 2 transactions
                for(int i=1; i<T.size(); i++)
                {
                    if((T[i-1].second - T[i].first) < min)
                    {
                        min = (T[i-1].second - T[i].first);
                        type = 1;
                        pos = i;
                    }
                    
                    if((T[i].second - T[i].first) < min)
                    {
                        min = T[i].second - T[i].first;
                        type = 0;
                        pos = i;
                    }
                }
                profit -= min;
                if(type == 0)
                    T.erase(T.begin()+pos);
                else
                {
                    T[pos-1].second = T[pos].second;
                    T.erase(T.begin()+pos);
                }
                
                diff--;
            }
            
        }
        
        return profit;
    }
};