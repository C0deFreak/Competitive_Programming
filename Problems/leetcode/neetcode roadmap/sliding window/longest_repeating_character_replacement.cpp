#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        const int len = s.size();
        int l=0;
        int freq[26] = {0};
        int ans = 0;
        int maxf = 0;
        
        for(int r=0; r<len; r++) {
            int rn = s[r] - 'A';
            freq[rn]++;
            // this works cus if something is less than maxf we don't care cus we got something better
            maxf = max(maxf, freq[rn]);
            // if we have more than k non-sames, se move the whole window one to right and check again
            if((r-l+1)-maxf > k) {
                freq[s[l]-'A']--;
                l++;
            } else ans = max(ans, r-l);
        }
        return max(ans, len-l);

    }
};