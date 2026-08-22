typedef pair<int,int> pip;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int sum = 0;
        vector <vector <pip>> graph(V);
        for(auto e : edges){
            int s = e[0];
            int d = e[1];
            int wt = e[2];
            graph[s].push_back({d,wt});
            graph[d].push_back({s,wt});
        }
        vector <int> vis(V,0);
        priority_queue <pip,vector <pip>,greater <pip>> pq;
        pq.push({0,0}); // {distance,Vertix}
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int v = p.second;
            if(vis[v]==1) continue;
            vis[v]=1;
            sum += d;
            for(auto g : graph[v]){
                int nbr = g.first;
                int wt = g.second;
                if(vis[nbr]==0){
                    pq.push({wt,nbr});
                }
            }
        }
        return sum;
    }
};