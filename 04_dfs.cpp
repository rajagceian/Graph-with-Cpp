#include <iostream>
#include <vector>

using namespace std;
void f(int src,vector<vector<int>>& adj,vector <bool> &isVis,vector <int> &ans){
    isVis[src]=true;
    ans.push_back(src);
    for(int nbr : adj[src]){
        if(!isVis[nbr]){
            f(nbr,adj,isVis,ans);
        }
    }
}
//T.C => O(V+E)
vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    int n = adj.size();
    vector <int> ans;
    vector <bool> isVis(n,false);
    f(0,adj,isVis,ans);
    return ans;
}
int main(){

}