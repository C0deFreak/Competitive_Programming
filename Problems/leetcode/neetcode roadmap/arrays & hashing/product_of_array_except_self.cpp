#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int l = nums[0];
        int r = nums[len-1];
        vector<int> ans(len, 1);
        for(int i=1; i<len; i++) {
            ans[i] *= l;
            l *= nums[i];
            ans[len-1-i] *= r;
            r *= nums[len-1-i];
        }
        return ans;
    }
};