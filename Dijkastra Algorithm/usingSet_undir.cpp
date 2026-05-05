#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

    vector<int> dijkstra(int V, vector<vector<int>> &edge, int src) { 
        //T.C => O((V+E)*logV) and S.C => O(V+E)
 
        vector <vector <pair<int,int>>> graph(V);
        for(int i=0;i<edge.size();i++){
            int u = edge[i][0];
            int v = edge[i][1];
            int wt = edge[i][2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        set <pair<int,int>>st;
        vector <int> dist(V,INT_MAX);
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto it = *(st.begin());
            int currDist = it.first;
            int currVer = it.second;
            st.erase(it);
            if (currDist > dist[currVer]) continue;
            for(auto it : graph[currVer]){
                int nbrVer = it.first;
                int nbrW = it.second;
                if(currDist + nbrW < dist[nbrVer]){
                    if(dist[nbrVer] != INT_MAX){
                        st.erase({dist[nbrVer],nbrVer});
                    }
                    dist[nbrVer] = currDist + nbrW;
                    st.insert({dist[nbrVer],nbrVer});
                }
            }
        }
        return dist;
    }

int main() {

return 0;
}