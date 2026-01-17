#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // similar to trapping rain water
        int small=0;
        int ans = 0;

        for(int i=1; i<prices.size(); i++) {
            // get to the smallest price, if i is smaller we set small to i
            if(prices[i] < prices[small]) {
                small = i;
            // if i is bigger than small and the diff is bigger than ans we set ans to diff
            } else if(prices[i]-prices[small] > ans) ans = prices[i]-prices[small];
        }
        return ans;
    }
};