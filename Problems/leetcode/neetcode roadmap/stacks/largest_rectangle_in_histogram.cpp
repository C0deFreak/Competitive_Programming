#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> sizes;
        // so we can compute the rest of the array
        heights.push_back(0);

        for(int i=0; i<heights.size(); i++) {
            /* if the current height is smaller then the top of the stack, it will:
            calculate the area of the top of stack (width is from element left of top to current element)
            pop the last element, try again */
            while(!sizes.empty() && heights[sizes.top()] > heights[i]) {
                int h = sizes.top();
                sizes.pop();
                int w = i;
                if (!sizes.empty()) w=i-sizes.top()-1;
                ans = max(ans, heights[h]*w);
                
            }
            sizes.push(i);
        }
        return ans;
    }
};