class Solution {
  public:
    bool dfs(int src,vector <vector <int>> &graph,int parent,vector <int> &isVis){
        isVis[src]=1;
        for(int nbr : graph[src]){
            if(isVis[nbr] && nbr != parent){
                return true;
            }
            if(!isVis[nbr])
              if(dfs(nbr,graph,src,isVis))
              return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector <vector <int>> graph(V);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector <int> isVis(V);
        for(int i=0;i<V;i++){
            if(!isVis[i] && dfs(i,graph,-1,isVis)){   //src,graph,parent)
                return true;
            }
        }
         return false;
    }
};