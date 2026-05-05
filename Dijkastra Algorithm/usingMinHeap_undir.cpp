#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

    vector<int> dijkstra(int V, vector<vector<int>> &edge, int src) {
        //T.C => O((V+E)*logV) and S.C => O(V+E)
        vector <vector <pair<int,int>>> graph(V);
        for(int i=0;i<edge.size();i++){
            int u = edge[i][0];
            int v = edge[i][1];
            int wt = edge[i][2];
            graph[u].push_back({v,wt});
           // graph[v].push_back({u,wt}); // bcz of undirected Graph
        }
        priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>> minHeap; // Dist and Vertex
        vector <int> dist(V,INT_MAX);
        dist[src]=0;
        minHeap.push({0,src});
        while(!minHeap.empty()){
            int currDist = minHeap.top().first;
            int currVer = minHeap.top().second;
            minHeap.pop();
            if (currDist > dist[currVer]) continue;
            for(auto it : graph[currVer]){
                int nbrVer = it.first;
                int nbrW = it.second;
                if(currDist + nbrW < dist[nbrVer]){
                    dist[nbrVer] = currDist + nbrW;
                    minHeap.push({dist[nbrVer],nbrVer});
                }
            }
        }
        return dist;
    }

int main() {

return 0;
}