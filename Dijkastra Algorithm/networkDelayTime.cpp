// • Time Complexity → O((V + E) log V)
// • Space Complexity → O(V + E)
// weight is positive
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector <pair<int,int>>> graph(n+1); // n+1 => node is from 1 to n
        for(int i=0;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int wt = times[i][2];
            graph[s].push_back({d,wt});
        }
        vector <int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(pq.size()){
            auto [d,v] = pq.top();
            pq.pop();
            if(d>dist[v]) continue;
            for(auto [nbr,wt] : graph[v]){
                if(d+wt < dist[nbr]){
                    dist[nbr] = d+wt;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        int res=INT_MIN;
        for(int i=1;i<=n;i++) { //required => 1 to n
            res = max(res,dist[i]);
        }
        return res==INT_MAX ? -1 : res;
    }
};