#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;
int V;
vector <list <int>> graph;
unordered_set <int> vis;

void addEdge(int src,int des,bool isBiDir = true){
    graph[src].push_back(des);
    if(isBiDir){
        graph[des].push_back(src);
    }
}

bool dfs(int curr,int des){
    if(curr == des) return true;

    vis.insert(curr);// mark visited
    for(auto nbr : graph[curr]){
        if(not vis.count(nbr)){
            bool res = dfs(nbr,des);
            if(res) return true;
        }
    }
    return false;
}

bool anyPath(int src,int des){ // T.C => O(V+E)
    vis.clear();
    return dfs(src,des);
}
int main() {
    cin>>V;
    graph.resize(V,list<int>());
    
    int e;
    cin>>e;
    while(e--){
        int s,d; // Edage b/w S and D.
        cin>>s>>d;
        addEdge(s,d); // Undirected => T.C = O(E) and S.C = O(V + 2*E) ; { 2*E bcz Each edge is stored twice → (u→v and v→u) }

     // addEdge(s,d,false); // Directed => T.C = O(E) and S.C = O(V + E)
    }
    int s,tar;
    cin>>s>>tar;
    cout<<anyPath(s,tar)<<endl;
return 0;
}