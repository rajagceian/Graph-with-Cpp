#include <iostream>
#include <vector>
using namespace std;

    int m,n;
    void f(vector<vector<int>>& image, int i, int j, int color,int c){
        image[i][j] = color;
        if(i>0 && image[i-1][j]==c) f(image,i-1,j,color,c); // up
        if(j>0 && image[i][j-1]==c) f(image,i,j-1,color,c); // left
        if(j<n-1 && image[i][j+1]==c) f(image,i,j+1,color,c); // right
        if(i<m-1 && image[i+1][j]==c) f(image,i+1,j,color,c); // down
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int c = image[sr][sc];
        if (c == color) return image;   
        f(image,sr,sc,color,c);
        return image;
    }

int main() {

return 0;
}