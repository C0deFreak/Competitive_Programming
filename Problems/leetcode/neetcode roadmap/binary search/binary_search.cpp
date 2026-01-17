#include <bits/stdc++.h>
using namespace std;

// An array of size 8 we can cut in half 3 times (2**3 == 8), so it is O(3)
// to get the time we use log of 2 (2**3 = 8 -> log 8 = 3) so time is O(log n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        // we cut of the half in which the target cant be and repeat that until mid is target or until r<l
        while(r >= l) {
            int mid = int((l+r)/2);
            if(nums[mid]<target) l=mid+1;
            else if (nums[mid]>target) r=mid-1;
            else return mid;
        }
        return -1;
    }
};