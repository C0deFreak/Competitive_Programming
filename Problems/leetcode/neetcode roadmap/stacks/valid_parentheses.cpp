#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // stack<type> -> push(val), pop(), top(), empty()
        stack<char> last;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        // ako je zatvornik i nema odgovrajući otvornik na kraju lasta vraća false
        // ako je otvornik samo ga doda na kraj
        for(char b:s) {
            if(pairs[b]) {
                if(!last.empty() && pairs[b] == last.top()) last.pop();
                else return false;
            } else last.push(b);
        }
        // ako je ostalo u lastu znači da imamo nepotrebnih zagrada
        if(last.empty()) return true;
        return false;
    }
};