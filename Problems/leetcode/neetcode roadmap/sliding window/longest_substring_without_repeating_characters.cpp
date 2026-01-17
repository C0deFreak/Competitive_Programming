#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // could use a hash but this is faster
        int digi[128] = {0};
        const int len = s.size();
        int ans = 0;
        int last = 0;

        for(int i=0; i<len; i++) {
            // if we already had this char, we compare the current sub and ans, and set the first element of sub to be one above the duplicate
            if(digi[s[i]] && digi[s[i]]-1 >= last) {
                ans = max(ans, i-last);
                last = digi[s[i]];  
            }
            digi[s[i]] = i+1;
        }
        return max(ans, len-last);
    }
};