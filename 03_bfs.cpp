#include <iostream>
#include <vector>

using namespace std;
//T.C => O(V+E)
vector<int> bfs(vector<vector<int>> &adj) {
    // code here
    int n = adj.size();
    vector <bool> isVis(n,false);
    vector <int> ans;
    queue <int> q;
    q.push(0);
    isVis[0]=true;
    while(q.size()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int nbr : adj[node]){
            if(!isVis[nbr]){
                isVis[nbr]=true;
                q.push(nbr);
            }
        }
    }
    return ans;
}

int main(){

}