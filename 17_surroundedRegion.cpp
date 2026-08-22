//Leetcode => 130
// ================ T.C = O(n*m) ====================
class Solution {
public:
    int y[4] = {-1,0,1,0};
    int x[4] = {0,1,0,-1};
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j< 0 || i>=m || j>=n) return false;
        return true;
    }
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
        board[i][j] = '#';
        for(int k=0;k<4;k++){
            int r = i + y[k];
            int c = j + x[k];
            if(isValid(r,c,m,n) && board[r][c]=='O'){
                dfs(r,c,m,n,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int row : {0,m-1}){
            for(int j=0;j<n;j++){
                if(board[row][j]=='O'){
                    dfs(row,j,m,n,board);
                }
            }
        }
        for(int col : {0,n-1}){
            for(int i=0;i<m;i++){
                if(board[i][col]=='O'){
                    dfs(i,col,m,n,board);
                }
            }
        }
        //Update the final board
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                  board[i][j]='X';
                else if(board[i][j]=='#')
                  board[i][j]='O';
            }
        }
    }
};