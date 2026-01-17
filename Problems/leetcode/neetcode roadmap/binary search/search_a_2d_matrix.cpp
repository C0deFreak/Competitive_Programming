#include <bits/stdc++.h>
using namespace std;

// Time O(m * log n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we go through rows until we find one in which the target can be in, skip otherwise
        for(auto row: matrix) {
            if(row[0] <= target && target <= row.back()) {
                // binary search algo
                int l=0, r=row.size()-1;

                while(l<=r) {
                    int mid = int((l+r)/2);
                    if(row[mid]<target) l=mid+1;
                    else if(row[mid]>target) r=mid-1;
                    else return true;
                }
                return false;
            }
        }
        return false;
    }
};