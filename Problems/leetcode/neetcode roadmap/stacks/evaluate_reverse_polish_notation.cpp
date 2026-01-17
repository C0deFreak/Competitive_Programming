#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int first, second;

        for(string s:tokens) {

            if(s == "+" || s == "/" || s == "-" || s == "*") {
                first = nums.top();
                nums.pop();
                second = nums.top();
                nums.pop();
                
                if(s == "+") nums.push(first+second);
                else if(s == "*") nums.push(first*second);
                else if(s == "-") nums.push(second-first);
                else nums.push(int(second/first));

            } else nums.push(stoi(s));

        }

        return nums.top();
    }
};