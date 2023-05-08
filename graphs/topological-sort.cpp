// Link: https://practice.geeksforgeeks.org/problems/topological-sort/1?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        
        for(int& n: adj[node]) {
            if(!vis[n]) {
                dfs(n, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans(V);
	    vector<bool> vis(V);
	    
	    for(int i = 0; i < V; i++)
	        vis[i] = false;
	       
	    stack<int> st;
	    
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, adj, vis, st);
	        }
	    }
	    
	    /// pop all the entries from the stack
	    int i = 0;
	    while(!st.empty()) {
	        ans[i++] = st.top();
	        st.pop();
	    }
	    
	    return ans;   
	}
};