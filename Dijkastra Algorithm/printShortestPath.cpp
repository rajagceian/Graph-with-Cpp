//https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector <vector <pair<int,int>>> graph(n+1);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int> dist(n+1,INT_MAX),parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        dist[1] = 0;
        minHeap.push({0,1});
        while(minHeap.size()){
            int currDist = minHeap.top().first;
            int currVer = minHeap.top().second;
            minHeap.pop();
            
            if(currDist > dist[currVer]) continue;
            
            for(auto nbr : graph[currVer]){
                int ver = nbr.first;
                int wt = nbr.second;
                
                if(currDist + wt < dist[ver]){
                    dist[ver] = currDist + wt;
                    parent[ver] = currVer;
                    minHeap.push({dist[ver],ver});
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        
        vector <int> path;
        int currVer = n;
        while(parent[currVer] != currVer){
            path.push_back(currVer);
            currVer = parent[currVer];
        }
        path.push_back(currVer);
        reverse(path.begin(),path.end());
        
        return path;
    }

int main() {

return 0;
}