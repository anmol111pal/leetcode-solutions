// Link: https://practice.geeksforgeeks.org/problems/214734e358208c1c6811d9b237b518f6b3c3c094/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n);
        stack<long long> st;
        st.push(-1);
        
        int i=n-1, x=n-1;
        
        while(i >= 0) {
            
            int curr = arr[i];
            
            if(curr < st.top()) {
                ans[x--] = st.top();
                st.push(curr);
            }
            
            else { // curr >= st.top()
                
                while(!st.empty() && curr >= st.top())
                    st.pop();
                
                if(st.empty()) 
                    ans[x--] = -1; // no greater elem
                else
                    ans[x--] = st.top();
                st.push(curr);
            }
            i--;
        }
        
        return ans;
    }
};