// Link: https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st; // first-> top, second-> minimum
public:
    MinStack() {
        ;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val}); // it is the minimum itself
        }

        else {
            int min = st.top().second; // fetch the minimum so far
            if(val >= min)
                st.push({val, min}); // minimum will be the prev min
            else
                st.push({val, val}); // update the min
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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