#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<tuple<int, int>> wait;
        vector<int> ans(temperatures.size(), 0);

        for(int i=temperatures.size()-1; i>=0; i--) {
            while(!wait.empty() && get<0>(wait.top()) <= temperatures[i]) wait.pop();
            if(!wait.empty()) ans[i] = get<1>(wait.top())-i;
            wait.push({temperatures[i], i});
        }
        return ans;
    }
};