#include <iostream>
#include <vector>
#include <list>
using namespace std;

int V; // no. of vertices
vector <list<int>> graph;

void addEdge(int src,int des,bool isBidir = true){
    graph[src].push_back(des);
    if(isBidir){
        graph[des].push_back(src);
    }
}

void print(){
    for(int i=0;i<V;i++){
        cout<<i<<" -> ";
        for(auto nbr : graph[i]){
            cout<<nbr<<" ";
        }
        cout<<endl;
    }
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
    print();
return 0;
}