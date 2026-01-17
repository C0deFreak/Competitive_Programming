#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        const int len = s.size();
        int l=0, r=len-1;

        while(l<r) {
            while(l<len && !isdigit(s[l]) && !isalpha(s[l])) {
                l++;
            }
            while(r>=0 && !isdigit(s[r]) && !isalpha(s[r])) {
                r--;
            }

            if(r>=0 && l<len && tolower(s[r]) != tolower(s[l])) return false;
            r--;
            l++;
        }

        return true;
    }
};