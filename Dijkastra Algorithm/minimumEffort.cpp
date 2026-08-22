// Leetcode => 1631
//--------- T.C = O((N × M) log(N × M)) --- S.C = O(N x M)-------
class Solution {
public:
    int y[4] = {0,1,0,-1};
    int x[4] = {-1,0,1,0};
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector <vector <int>> dist(n,vector <int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});//{dist,{row,col}}
        while(pq.size()){
            auto [d,p] = pq.top();
            pq.pop();
            int i=p.first;
            int j=p.second;
            if(d > dist[i][j]) continue;
            for(int k=0;k<4;k++){
                int r = i + y[k];
                int c = j + x[k];
                if(!isValid(r,c,n,m)) continue;
                int diff = abs(heights[i][j]-heights[r][c]);
                int newWt = max(diff,d);
                if(newWt < dist[r][c]){
                    dist[r][c] = newWt;
                    pq.push({dist[r][c],{r,c}});
                }
            }
        }
        return heights[n-1][m-1];
    }
};