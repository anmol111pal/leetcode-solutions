#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();

        int max_profit = INT_MIN;
        int min_price = prices[0];

        for(int i=0; i<n; ++i) {
            min_price = min(min_price, prices[i]);
            
            int curr_profit = prices[i] - min_price;
            max_profit = max(max_profit, curr_profit);    
        }

        // no profit made
        if(max_profit == INT_MIN)
            max_profit = 0;

        return max_profit;
    }
};