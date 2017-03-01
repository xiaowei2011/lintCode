#include"utils.h"
class Solution {
public:
	/**
	* @param n an integer
	* @param edges a list of undirected edges
	* @return true if it's a valid tree, or false
	*/

	//BFS
	bool validTree1(int n, vector<vector<int>>& edges) {
		if (edges.size() != n - 1)
			return false;
		vector<vector<bool>> graph(n, vector<bool>(n));
		for (vector<int> &vec : edges)
			graph[vec[0]][vec[1]] = graph[vec[1]][vec[0]] = true;
		map<int, bool> visited;
		queue<int> q;
		q.push(0);
		while (!q.empty()){
			int id = q.front();
			q.pop();
			visited[id] = true;
			for (int i = 0; i < n; i++){
				if (graph[id][i] && !visited[i]){
					q.push(i);
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (!visited[i])
				return false;
		}
		return true;
	}
	//DFS
	bool validTree2(int n, vector<vector<int>>& edges) {
		if (edges.size() != n - 1)
			return false;
		vector<vector<bool>> graph(n, vector<bool>(n));
		for (vector<int> &vec : edges)
			graph[vec[0]][vec[1]] = graph[vec[1]][vec[0]] = true;
		vector<bool> visited(n);
		dfs(graph, visited, 0);
		for (int i = 0; i < n; i++){
			if (!visited[i])
				return false;
		}
		return true;
	}
	void dfs(const vector<vector<bool>> &graph, vector<bool> &visited, int node){
		visited[node] = true;
		for (int i = 0; i < graph.size(); i++){
			if (graph[node][i] && !visited[i]){
				dfs(graph, visited, i);
			}
		}
	}

	bool validTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> neighs(n);
		for (const auto &edge : edges){
			neighs[edge[0]].push_back(edge[1]);
			neighs[edge[1]].push_back(edge[0]);
		}
		vector<bool> visited(n);
		if (haveCycle(neighs, visited, 0, -1))
			return false;
		for (int i = 0; i < n; i++){
			if (!visited[i])
				return false;
		}
		return true;
	}
	bool haveCycle(const vector<vector<int>> &neighs,vector<bool> &visited,int node,int pa){
		if (visited[node])
			return true;
		visited[node] = true;
		for (auto i : neighs[node]){
			if (i != pa && haveCycle(neighs, visited, i, node)){
				return true;
			}
		}
		return false;
	}
	void test(){
		vector<vector<int>> vec = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 } };
		cout << validTree(5, vec) << endl;
	}
};