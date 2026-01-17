#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int len = nums.size();
        
        // need to sort
        sort(nums.begin(), nums.end());
        if(nums[len-1]<0 || nums[0]>0 || !len) return {};
           
        for(int i=0; i<len-2; i++) {
            int j=i+1, k=len-1;
            // once i gets bigger than 0, sum is always gonna be more so we break
            if(nums[i] > 0) break;
            // we skip the same i to avoid duplicates cus we already checked everything with that i
            if(i && nums[i-1] == nums[i]) continue;
            while(k>j) {
                // if it is less than 0 we increase j to increase it
                if(nums[j]+nums[k]+nums[i] < 0) {
                    j++;
                // if the sum is more than 0, we need to lower it so we lower k
                } else if (nums[j]+nums[k]+nums[i] > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    // if we add something to ans, and the next j is the same we skip it to avoid duplicates
                    while(nums[j] == nums[j-1] && j<k) j++;
                }
            }
            
        }
        

        return ans;
    }
};