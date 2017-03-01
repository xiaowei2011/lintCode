#include"utils.h"
#include<algorithm>
struct DirectedGraphNode {
	int label;
	vector<DirectedGraphNode *> neighbors;
	DirectedGraphNode(int x) : label(x) {};
	friend ostream& operator<<(ostream &out, const DirectedGraphNode* node){
		out << node->label;
		return out;
	}
};
class Solution {
public:
	/**
	* @param graph: A list of Directed graph node
	* @return: Any topological order for the given graph.
	*/
	//每次删除没有出度为0的节点
	vector<DirectedGraphNode*> topSort1(vector<DirectedGraphNode*> graph) {
		vector<DirectedGraphNode *> vec;
		DirectedGraphNode *node = NULL;
		int len = graph.size();
		while (len-- > 0){
			for (int i = 0; i < graph.size(); i++){
				if (graph[i]->neighbors.empty()){
					vec.push_back(graph[i]);
					node = graph[i];
					graph.erase(graph.begin() + i);
					i--;
					for (int j = 0; j < graph.size(); j++){
						for (int k = 0; k < graph[j]->neighbors.size(); k++){
							if (graph[j]->neighbors[k] == node){
								graph[j]->neighbors.erase(graph[j]->neighbors.begin() + k);
								k--;
							}
						}
					}
					break;
				}
			}
		}
		reverse(vec.begin(), vec.end());
		return vec;
	}
	//使用map记录入度
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
		vector<DirectedGraphNode*> vec;
		map<DirectedGraphNode*, int> m;
		vector<DirectedGraphNode*> temp;
		for (auto node : graph){
			for (auto n : node->neighbors){
				m[n]++;
			}
		}
		for (auto node : graph){
			if (m[node] == 0){
				temp.push_back(node);
			}
		}
		while (!temp.empty()){
			vec.push_back(temp.back());
			temp.pop_back();
			for (auto node : vec.back()->neighbors){
				if (--m[node] == 0){
					temp.push_back(node);
				}
			}
		}
		return vec;
	}
	
	void test(){
		vector<DirectedGraphNode*> vec = { new DirectedGraphNode(0), new DirectedGraphNode(1), new DirectedGraphNode(2),
			new DirectedGraphNode(3), new DirectedGraphNode(4), new DirectedGraphNode(5) };
		vec[0]->neighbors = { vec[1], vec[3] };
		vec[1]->neighbors = { vec[2] };
		vec[2]->neighbors = { vec[3], vec[4] };
		vec[3]->neighbors = { vec[4] };
		Utils::print(topSort(vec));
	}
};