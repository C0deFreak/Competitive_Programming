#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hashmap key can't be a vector
        unordered_map<string, vector<string>> ans;

        for(auto s:strs) {
            string code = s;
            sort(code.begin(), code.end());
            ans[code].push_back(s);
        }

        vector<vector<string>> res;
        for(auto a:ans) res.push_back(a.second);
        return res;
    }
};