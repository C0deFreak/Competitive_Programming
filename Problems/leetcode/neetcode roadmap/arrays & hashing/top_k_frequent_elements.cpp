#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n:nums) freq[n]++;

        // you define a tuple with element types, not the amount
        vector<tuple<int, int>> place;
        // you get the hash key with .first and the value with .second
        for(auto f:freq) place.push_back({f.second, f.first});
        // insted of that mumbo jumbo of lambda, use greater or less
        sort(place.begin(), place.end(), greater<>());

        vector<int> ans;
        // tuple[0] doesnt work, you need get<0>(tuple)
        for(int i=0; i<k; i++) ans.push_back(get<1>(place[i]));

        return ans;

    }
};