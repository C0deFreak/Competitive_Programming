#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int len = deck.size();
        vector<int> order(len);
        // you can add and remove from front and back
        deque<int> next;

        for(int i=0; i<len; i++) { 
            next.push_back(i);
        }
        sort(deck.begin(), deck.end(), greater<>());
        // you reveal every other card
        int odd = false;
        // you have an array with positions as you go through the deck (next)
        // when you reveal a card, you add it to the position you are on rn
        // then you remove the card (remove top of next - positions and bottom of (cus its reversed) deck - card value)
        while(deck.size()) {
            if(odd) {
                next.push_back(next[0]);
            } else {
                order[next[0]] = deck.back();
                deck.pop_back();
            }
            next.pop_front();
            odd = !odd;
        }
        
        return order;
    }
};