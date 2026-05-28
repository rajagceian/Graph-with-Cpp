//Leetcode => 778

//---------- Approach - 1 : Binary Search => T.C = O(n^2 * logn) and S.C = O(n*m) ---------
class Solution1 {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    bool bfs(int i,int j,int n,int m,vector<vector<int>>& grid,int money){
        int y[4] = {0,1,0,-1};
        int x[4] = {-1,0,1,0};
        vector<vector<int>> vis(n,vector <int> (m,0));
        queue <pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(q.size()){
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r==n-1 && c==m-1) return true;
            for(int k=0;k<4;k++){
                int row = r + y[k];
                int col = c + x[k];
                if(isValid(row,col,n,m) && vis[row][col]==0 && money>=grid[row][col]){
                    q.push({row,col});
                    vis[row][col] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int lo = grid[0][0];
        int hi = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hi = max(hi,grid[i][j]);
            }
        }
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(bfs(0,0,n,m,grid,mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};

//---------- Approach - 2 : Dijkastra Aglorithm  ---------
//--------- T.C = O((N × M) log(N × M)) --- S.C = O(N x M)-------
typedef pair<int,pair<int,int>> pip;
class Solution2 {
public:
    int y[4] = {0,1,0,-1};
    int x[4] = {1,0,-1,0};
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        pq.push({grid[0][0],{0,0}});
        vector <vector <int>> dist(n,vector <int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        while(pq.size()){
            auto [d,p] = pq.top();
            int i = p.first;
            int j = p.second;
            pq.pop();
            if(d > dist[i][j]) continue;
            for(int k=0;k<4;k++){
                int r = i + y[k];
                int c = j + x[k];
                if(!isValid(r,c,n,m)) continue;
                int time = max(d,grid[r][c]);
                if(time < dist[r][c]){
                    dist[r][c] = time;
                    pq.push({time,{r,c}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};