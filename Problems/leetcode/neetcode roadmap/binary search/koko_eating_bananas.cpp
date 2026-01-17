#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini=1, maxi=0;
        
        // max the speed needs to be is the size of biggest element in array
        for(int p:piles) maxi = max(maxi, p);

        int ans=maxi;
        // binary search for res in [1, max(piles)]
        while(mini<=maxi) {
            int mid = int((mini+maxi)/2);
            bool passed = true;
            int spent = h;
            for(int p:piles) {
                spent -= int((p+mid-1)/mid);
                if(spent < 0) passed = false;
            }
            // if koko can't eat everything in h, the answer must be larger
            if(!passed) mini=mid+1;
            // if koko can eat everything, then the answer is either this or something smaller
            else ans=min(mid, ans), maxi=mid-1;
        }
        return ans;
    }
};;