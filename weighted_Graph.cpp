#include <iostream>
#include <vector>
#include <list>
using namespace std;

int V; // no. of vertices
vector <list<pair<int,int>>> graph;

void addEdge(int src,int des,int wt,bool isBidir = true){
    graph[src].push_back({des,wt});
    if(isBidir){
        graph[des].push_back({src,wt});
    }
}

void print(){
    for(int i=0;i<V;i++){
        cout<<i<<" -> ";
        for(auto nbr : graph[i]){
            cout<<"("<<nbr.first<<" , "<<nbr.second<<") ";
        }
        cout<<endl;
    }
}
int main() {
    cin>>V;
    graph.resize(V,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt; // Edage b/w S and D, wt = weight
        cin>>s>>d>>wt;
        addEdge(s,d,wt); // Undirected => T.C = O(E) and S.C = O(V + 2*E) ; { 2*E bcz Each edge is stored twice → (u→v and v→u) }

     // addEdge(s,d,wt,false); // Directed => T.C = O(E) and S.C = O(V + E)
    }
    print();
return 0;
}