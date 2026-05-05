// Graph => Simultaneously work ==> multi-source BFS
class Solution {
public:
    int x[4] = {-1,0,1,0};
    int y[4] = {0,1,0,-1};
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue <pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        while(q.size() && fresh>0){
            time++;
            int size = q.size();
            while(size--){
                pair<int,int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for(int k=0;k<4;k++){
                    int row = r + y[k]; // y=>i=>row
                    int col = c + x[k]; // x=>j=>col
                    if(isValid(row,col,m,n) && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col] = -2; // marked as rotten
                        fresh--;
                    }
                }
            }  
        }
        if(fresh>0) return -1;
        return time;
    }
};