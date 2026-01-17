#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // make freq of s2 elements
        array<int, 26> perm = {0};
        for(char s:s1) perm[s-'a']++;
        
        array<int, 26> tst = perm;
        int len = s1.size();
        array<int, 26> place = {0};
        int r = 0;
        while(r < s2.size()) {
            int curr = s2[r]-'a';
            // we know freq are same, so if len is 0 it is a permutation, faster than comparing arrays
            if(!len) return true;
            if(tst[curr]) {
                // follow the freq of s2 supposed permutation, if somethings off it aint a permutation
                tst[curr]--;
                len--;
                // in case all elements were part of s1 and now we may get a duplicate we will return to duplicate + 1
                if(!place[curr]) place[curr] = r+1;
            } else {
                tst = perm;
                len = s1.size();
                if(place[curr]) r = place[curr]-1;
                place.fill(0);
            }
            r++;
        }

        if(!len) return true;
        return false;
    }
};