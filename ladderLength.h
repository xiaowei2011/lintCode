#include"utils.h"
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<string>
class Solution {
public:
	/**
	* @param start, a string
	* @param end, a string
	* @param dict, a set of string
	* @return an integer
	*/
	//‘À––≥¨ ±
	int ladderLength1(string start, string end, unordered_set<string> &dict) {
		dict.insert(start);
		dict.insert(end);
		map<string, vector<string>> m;
		for (unordered_set<string>::iterator it1 = ++dict.begin(); it1 != dict.end(); it1++){
			for (unordered_set<string>::iterator it2 = dict.begin(); it2 != it1; it2++){
				if (dif(*it1, *it2)){
					m[*it1].push_back(*it2);
					m[*it2].push_back(*it1);
				}
			}
		}
		map<string, bool> visited;
		int length = 0;
		queue<string> q;
		q.push(start);
		while (!q.empty()){
			int len = q.size();
			length++;
			while (len-- > 0){
				string s = q.front();
				q.pop();
				visited[s] == true;
				if (s == end)
					return length;
				for (auto & ss : m[s]){
					if (!visited[ss])
						q.push(ss);
				}
			}
		}
		return 0;
	}
	bool dif(const string &a, const string &b){
		int count = 0;
		for (int i = 0; i < a.size(); i++){
			if (a[i] != b[i])
				count++;
			if (count > 1)
				return false;
		}
		return count == 1;
	}

	int ladderLength(string start, string end, unordered_set<string> &dict) {
		if (start == end)
			return 1;
		queue<string> q;
		q.push(start);
		map<string, int> m;
		m[start] = 1;
		dict.erase(start);
		while (!q.empty()){
			string s = q.front();
			q.pop();
			int length = m[s];
			for (int i = 0; i < s.size(); i++){
				string ts = s;
				for (int j = 'a'; j <= 'z'; j++){
					if (ts[i]==j)
						continue;
					else
						ts[i] = j;
					if (dict.find(ts) != dict.end()){
						q.push(ts);
						m[ts] = length + 1;
						dict.erase(ts);
					}
					if (ts == end){
						return length + 1;
					}
				}
			}
		}
		return 0;
	}

	vector<vector<string>> findLadders1(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> vec;
		unordered_map<string, vector<string>> m;
		unordered_set<string> visited;
		dict.insert(start);
		dict.insert(end);
		queue<string> q;
		q.push(start);
		int count = 1;
		bool found = false;
		while (!q.empty()){
			string s = q.front();
			q.pop();
			visited.insert(s);
			count--;
			if (s == end) found = true;
			for (int i = 0; i < s.size(); i++){
				string ts = s;
				for (int j = 'a'; j < 'z'; j++){
					if (ts[i]==j) continue;
					ts[i] = j;
					if (visited.find(ts) == visited.end() && dict.find(ts) != dict.end()){
						q.push(ts);
						m[s].push_back(ts);
					}
				}
			}
			if (count == 0){
				count = q.size();
			}
		}
	}
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		int len = start.size();
		vector<vector<string>> vec;
		unordered_map<string, vector<string>> next;
		unordered_map<string, int> vis;
		dict.insert(end);
		vis[start] = 0;
		queue<string> q;
		q.push(start);
		while (!q.empty()){
			string cur = q.front();
			q.pop();
			int step = vis[cur];
			for (int i = 0; i < len; i++){
				string ts = cur;
				for (char c = 'a'; c <= 'z'; c++){
					ts[i] = c;
					if (ts == cur || dict.find(ts) == dict.end()) continue;
					if (vis.find(ts) == vis.end()){
						q.push(ts);
						vis[ts] = step + 1;
					}
					next[cur].push_back(ts);
				}
			}
		}
		vector<string> path = { start };
		dfsPath(start, end, path, vis, next, vec);
		return vec;
	}
	void dfsPath(string cur,string end, vector<string> &path, unordered_map<string, int> &vis, unordered_map<string, vector<string>> &next,
		vector<vector<string>> &vec){
		if (cur == end){
			vec.push_back(path);
		}
		else if (vis[cur] < vis[end]){
			for (auto x : next[cur]){
				if (vis[x] > vis[cur]){
					path.push_back(x);
					dfsPath(x, end, path, vis, next, vec);
					path.pop_back();
				}
			}
		}
	}
	void test(){ 
		string start = "hit";
		string end = "cog";
		unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
		vector<vector<string>> vec = findLadders(start, end, dict);
		cout <<"size:"<< vec.size() << endl;
		Utils::print(vec);
	}
};