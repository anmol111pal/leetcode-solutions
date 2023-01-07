#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int totalIceCreams = 0;
        
        int i = 0;
        while(coins != 0 && i<costs.size()) {
            if(coins >= costs[i]) { // we have more coins than the currect cost
                totalIceCreams++;
                coins -= costs[i];
                i++;
            }
            else // current cost is more the no. of coins
                break;
        }

        return totalIceCreams;      
    }
};  