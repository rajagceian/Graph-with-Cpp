//leetcode => https://leetcode.com/problems/all-paths-from-source-to-target/
#include <iostream>
#include <vector>
using namespace std;
    void dfs(vector<vector<int>>& g,vector<vector<int>>& ans,vector <int> &path,int curr){
        path.push_back(curr);
        if(curr == g.size()-1){
           // path.push_back(curr);
            ans.push_back(path);
            return;
        }
        //path.push_back(curr);
        for(auto nbr : g[curr]){
            dfs(g,ans,path,nbr);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <vector <int>> ans;
        vector <int> path;
        dfs(graph,ans,path,0);
        return ans;
    }
int main() {

return 0;
}