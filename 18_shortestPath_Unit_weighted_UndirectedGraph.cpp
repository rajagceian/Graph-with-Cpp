// =============== T.C => O(V+E) And S.C => O(V+E) =================

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector <vector <int>> graph(V);
        for(int i=0;i<edges.size();i++){
            int s = edges[i][0];
            int d = edges[i][1];
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        //vector <int> isVis(V);
        vector <int> ans(V,-1);
        queue <pair<int,int>> q; // <Node,distance>
        q.push({src,0});
        //isVis[src]=1;
        ans[src]=0;
        while(q.size()){
            auto p = q.front();
            q.pop();
            // ans[p.first] = p.second;
            for(int nbr : graph[p.first]){
                // if(isVis[nbr]==0){
                if(ans[nbr]==-1){
                    ans[nbr] = p.second + 1;
                    q.push({nbr,p.second+1});
                // isVis[nbr]=1;
                }
            }
        }
        return ans;
    }
};
