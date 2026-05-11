//Colouring of Graph => T.C = O(V+E) and S.C => O(V)
class Solution {
public:
    bool dfs(int src,int coloured,vector<vector<int>>& graph,vector <int>&col){
        for(int nbr : graph[src]){
            col[src]=coloured;
            if(col[nbr]==coloured) return false;
            if(col[nbr]==-1){
                if(!dfs(nbr,1-coloured,graph,col)) // 1-coloured => assign different colour
                 return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector <int> col(V,-1);
        for(int i=0;i<V;i++){ // Graph may be disconnected
            if(col[i]==-1){
                if(!dfs(i,0,graph,col)){ // 0=> colour1 and 1 => colour2
                    return false;
                }
            }
        }
        return true;
    }
};