#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*=========================================== DFS =========================================== */
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

/*=========================================== BFS =========================================== */
 vector <int> topoSortBFS(int V,vector <vector <int>>& edges){ //T.C = O(n*n)
    vector <vector <int>> graph(V);
    vector <int> inDegree(V,0);
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        inDegree[edges[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector <int> ans;
    while(q.size()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<graph[node].size();i++){
            int nbr = graph[node][i];
            inDegree[nbr]--;
            if(inDegree[nbr]==0){
                q.push(nbr);
            }
        }
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
    auto a = topoSort(V,edges);
return 0;
}