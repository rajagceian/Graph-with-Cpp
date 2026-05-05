class Solution {
public:
    // For 4 directions
    int x[4] = {-1,0,1,0}; 
    int y[4] = {0,1,0,-1};
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    void dfs(int i,int j,int m,int n,vector<vector<char>>& grid,vector <vector <int>>&isVis){
        isVis[i][j]=1;
        for(int k=0;k<4;k++){
            int row = i + x[k];
            int col = j + y[k];
            if(isValid(row,col,m,n) && grid[row][col]=='1' && isVis[row][col]==0){
                dfs(row,col,m,n,grid,isVis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector <vector <int>>isVis(m,vector <int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && isVis[i][j]==0){
                    dfs(i,j,m,n,grid,isVis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};