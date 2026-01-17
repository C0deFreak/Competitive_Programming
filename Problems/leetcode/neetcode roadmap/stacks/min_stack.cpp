#include <bits/stdc++.h>
using namespace std;

// ovo radi jer je stack (ako imaš 0, pa 2 dodat će 0 u obije i onda 2 u ans, ako tražiš min vrati 0, ako popaš pa onda min vrati 0)
// ako 2 pa 0 doda oba dva broja u oba stacka
class MinStack {
    stack<int> ans, mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        ans.push(val);
        if (mini.empty() || mini.top() >= val) mini.push(val);
    }
    
    void pop() {
        if (ans.top() == mini.top()) mini.pop();
        ans.pop();
    }
    
    int top() {
        return ans.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */