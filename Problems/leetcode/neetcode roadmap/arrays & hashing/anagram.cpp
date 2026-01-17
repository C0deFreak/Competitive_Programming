#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_code[26] = {0};
        int t_code[26] = {0};

        if (s.size() != t.size()) return false;

        for (int i = 0; i<s.size(); i++) {
            s_code[int(s[i]) - int('a')]++;
            t_code[int(t[i]) - int('a')]++;
        }

        // a_array == b_array doesnt work, you need the equal() algo
        return equal(begin(s_code), end(s_code), begin(t_code));
    }
};