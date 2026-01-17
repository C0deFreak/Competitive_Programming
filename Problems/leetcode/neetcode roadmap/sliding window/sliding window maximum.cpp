#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> maxN;

        for(int r=0; r<nums.size(); r++) {
            // if our newest element is larger then back element we pop it max until we pop everything
            while (maxN.size() && maxN.back() < nums[r]) maxN.pop_back();
            // add the element to back
            maxN.push_back(nums[r]);
            /* if our current biggest element is outside the window, we pop it but we will always at least have our current 
            element as the biggest, if not that one, then the next biggest after the one outside the window*/
            if (r>=k && nums[r-k] == maxN.front()) maxN.pop_front();
            // adding max to ans
            if (r>=k-1) ans.push_back(maxN.front());
        }
        return ans;
    }
};