class Solution {
public:
    int y[4] = {0,1,0,-1};
    int x[4] = {-1,0,1,0};
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    void dfs(int i,int j,int tar,vector<vector<int>>& image,vector<vector<int>>& isVis,int m,int n,int col){
        isVis[i][j] = 1;
        image[i][j] = col;
        for(int k=0;k<4;k++){
            int r = i + y[k];
            int c = j + x[k];
            if(isValid(r,c,m,n) && image[r][c]==tar && isVis[r][c]==0){
                dfs(r,c,tar,image,isVis,m,n,col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int col) {
        int m = image.size();
        int n = image[0].size();
        int tar = image[sr][sc];
        vector <vector <int>> isVis(m,vector<int>(n,0));
        dfs(sr,sc,tar,image,isVis,m,n,col);
        return image;
    }
};