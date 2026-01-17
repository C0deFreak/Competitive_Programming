#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s:strs)
        // int -> string = to_string()
        ans += to_string(s.size()) + "#" + s;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i != s.size()) {
            string num = "";
            while(s[i] != '#') {
                num += s[i];
                i++;     
            }
            
            // string -> int = stoi()
            int n = stoi(num);
            ans.push_back(s.substr(i+1, n));
            i+=n+1;
        }
        return ans;
    }
};
