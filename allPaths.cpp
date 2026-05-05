#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;
int V;
vector<list<int>> graph;
unordered_set<int> vis;
vector<string> paths;
void addEdge(int src, int des, bool isBiDir = true)
{
    graph[src].push_back(des);
    if (isBiDir)
    {
        graph[des].push_back(src);
    }
}

void dfs(int curr, int des, string path)
{
    if (curr == des)
    {
        paths.push_back(path);
        return;
    }

    vis.insert(curr); // mark visited
    for (auto nbr : graph[curr])
    {
        if (not vis.count(nbr))
        {
            dfs(nbr, des, path + "->" + to_string(nbr));
        }
    }
    vis.erase(curr);
}

void allPaths(int src, int des)
{ // T.C => O(V+E)
    vis.clear();
    paths.clear();
    dfs(src, des, to_string(src));
}
int main()
{
    cin >> V;
    graph.resize(V, list<int>());

    int e;
    cin >> e;
    while (e--)
    {
        int s, d; // Edage b/w S and D.
        cin >> s >> d;
        addEdge(s, d); // Undirected => T.C = O(E) and S.C = O(V + 2*E) ; { 2*E bcz Each edge is stored twice → (u→v and v→u) }

        // addEdge(s,d,false); // Directed => T.C = O(E) and S.C = O(V + E)
    }
    int s, tar;
    cin >> s >> tar;
    allPaths(s, tar);
    for (auto p : paths)
    {
        cout << p << endl;
    }
    return 0;
}