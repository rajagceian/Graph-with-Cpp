#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
    // Code here
const int INF = 1e8;
int V = dist.size();
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j],
                                        dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {

return 0;
}