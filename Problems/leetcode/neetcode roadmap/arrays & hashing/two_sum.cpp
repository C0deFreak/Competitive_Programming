#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> chck;
        int diff;
        for(int i=0; i<nums.size(); i++) {
            diff = target-nums[i];
            // if find() can't find a value, it returns .end()
            if(chck.find(diff) != chck.end()) return {chck[diff], i};
            chck[nums[i]] = i;
        }
        return {};
    }
};