#include <bits/stdc++.h>
using namespace std;

// Time of O(2(n+m)) -> O(n+m)
class Solution {
public:
    string minWindow(string s, string t) {
        const int m=s.size(), n=t.size();
        // there is no need to check
        if(n>m) return "";
        
        // adding freq for t, but this time we are going to increase sFreq instead of copying tFreq to it and decreasing
        // if you know the possible amount of elements it is faster to use int array than hashmap
        int tFreq[58];
        int sFreq[58];
        for(char c:t) tFreq[c-'A']++;
        
        // answer range
        vector<int> ans = {0, m+1};
        
        // a missleading name but here we track if we have all n elements of t in our answer
        int len = n;
        int l=0, r=0;
        while(r<m) {
            // we need the leftmost element to be part t since we are looking for the smallest window
            while(!tFreq[s[l]-'A'] && l<r) l++;
            
            // if all elements of t are in our current window
            if(!len) {
                // checking if it is smaller than our best
                if (r-l+1 < ans[1]-ans[0]) ans={l, r+1};
                sFreq[s[l]-'A']--;
                /* if (for example) t has one A but our current window has two, 
                one of which we just removed since it was at the end of the window,
                all elements of t are still in window, so we check again (dont increase r)
                if this is not the case, we lost one element so this is not a possible answer
                and we will increase r */
                if (tFreq[s[l]-'A'] > sFreq[s[l]-'A']) len++;
                l++;
            } else {
                // adding char to sFreq if tFreq has it
                if(tFreq[s[r]-'A']) {
                    sFreq[s[r]-'A']++;
                    /* we only say we have another char in common with tFreq if the the freq for current
                    character is less or equal to the frq of this char in tFreq, otherwise we just have a duplicate
                    that we do not count thorwards the solution*/
                    if (tFreq[s[r]-'A'] >= sFreq[s[r]-'A']) len--;
                }
                
            }
            // increase r only when we dont have a correct current window
            if(len) r++;
        }

        // we translate our range to string answer
        string res;
        for(int i=ans[0]; i<ans[1]; i++) res+=s[i];
        if(ans[1]>m) return "";
        return res;
    }
};