#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector <int> dist(V,1e8);
    dist[src]=0;
    for(int i=0;i<V;i++){  // 'V-1' relaxation
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    
    // One more Relaxation to check Negative Cycle
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        
        if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
            // negative cycle detected
            return {-1};
        }
    }
    return dist;
}

int main() {

return 0;
}