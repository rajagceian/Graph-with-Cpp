#include <iostream>
#include <vector>
#include <stack>

using namespace std;

    void dfs(int src,vector<vector <int>> &graph,stack <int> &st,vector <int>&vis){
        vis[src] = 1;
        for(auto nbr : graph[src]){
            if(!vis[nbr]){
                dfs(nbr,graph,st,vis);
            }
        }
        st.push(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector <vector <int>> graph(V);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        stack <int> st;
        vector <int> ans,vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,graph,st,vis);
        }
        
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
int main() {
    int V,n; // V = no. of vertrices
    cin>>V>>n;
    vector <vector<int>> edges;
    while(n--){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    topoSort(V,edges);
return 0;
}