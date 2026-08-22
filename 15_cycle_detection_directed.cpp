class Solution {
	public:
	bool dfs(int src, vector <vector <int>> &graph, vector <int> &isVis, vector <int> &path) {
		isVis[src] = 1;
		path[src] = 1;
		for (int nbr : graph[src]) {
			if (!isVis[nbr])
				if (dfs(nbr, graph, isVis, path))
					return true;
			if (path[nbr])
				return true;
		}
		// remove from path
		path[src] = 0;
		return false;
	}
	bool isCyclic(int V, vector<vector<int>> & edges) {
		// Code here
		vector <vector <int>> graph(V);
		for (int i = 0; i<edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
		}
		vector <int> isVis(V);
		vector <int> path(V);
		for (int i = 0; i<V; i++) {
			if (!isVis[i] && dfs(i, graph, isVis, path)) {
				return true;
			}
		}
		return false;
	}
};
