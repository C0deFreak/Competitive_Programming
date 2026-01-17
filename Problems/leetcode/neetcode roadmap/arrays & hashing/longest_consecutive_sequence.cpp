#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(), nums.end());
        int ans = 0;

        for(int n:nums) {
            // lakši find() algo
            if(nset.find(n-1) == nset.end()) {
                // briše n
                nset.erase(n);
                int temp = 1;
                while(nset.find(n+temp) != nset.end()) {
                    nset.erase(n+temp);
                    temp++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};