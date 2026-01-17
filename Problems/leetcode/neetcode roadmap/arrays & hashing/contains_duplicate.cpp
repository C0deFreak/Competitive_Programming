#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // when you want to conver vector to set, you define a range
        set<int> check(nums.begin(), nums.end());
        return (check.size() != nums.size());
    }
};