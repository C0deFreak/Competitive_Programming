#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<tuple<int, float>> cars;
        for(int i=0; i<speed.size(); i++) cars.push_back({position[i], float(target-position[i])/float(speed[i])});
        sort(cars.begin(), cars.end(), greater<>());

        stack<float> ans;
        for(tuple c:cars) {
            if(ans.empty() || get<1>(c) > ans.top()) ans.push(get<1>(c));
        }
        return ans.size();
    }
};