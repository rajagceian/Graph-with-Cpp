// using bellman Ford's Algorithm => T.C = O(K x E),E = size of flight, and S.C = O(n)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector <int> dist(n,INT_MAX);
        
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector <int> prev=dist;
            for(auto f : flights){
                int s = f[0];
                int d = f[1];
                int wt = f[2];
                if(prev[s]!=INT_MAX && prev[s]+wt < dist[d]){
                    dist[d] = prev[s]+wt;
                }
            }
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};