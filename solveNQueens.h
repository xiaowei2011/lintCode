#include"utils.h"
#include<string>
class Solution {
public:
	/**
	* Get all distinct N-Queen solutions
	* @param n: The number of queens
	* @return: All distinct solutions
	* For example, A string '...Q' shows a queen on forth position
	*/
	vector<vector<string>> solveNQueens1(int n) {
		vector<vector<string>> vec;
		vector<string> base;
		solve(n, base, vec);
		return vec;
	}

	void solve(int n, vector<string> &base, vector<vector<string>> &vec){
		if (base.size() == n && coexist(base)){
			vec.push_back(base);
		}
		else if (base.size() < n){
			int len = n;
			for (int i = 0; i < n; i++){
				string cur(n, '.');
				cur[i] = 'Q';
				base.push_back(cur);
				solve(n, base, vec);
				base.pop_back();
			}
		}
	}
	bool coexist(vector<string> vec){
		for (int i1 = 0; i1 < vec.size(); i1++){
			for (int j1 = 0; j1 < vec[i1].size(); j1++){
				if (vec[i1][j1] == 'Q'){
					for (int i2 = i1 + 1; i2 < vec.size(); i2++){
						for (int j2 = 0; j2 < vec[i2].size(); j2++){
							if (vec[i2][j2] == 'Q'){
								int x = i2 - i1;
								int y = j2 - j1;
								if (y == 0 || x == y || x == -y)
									return false;
							}
						}
					}
					break;
				}
			}
		}
		return true;
	}
	vector<vector<string>> solveNQueens(int n){
		vector<int> a(n,-1);
		vector<vector<string>> vec;
		solve(n, 0, a, vec);
		return vec;
	}
	void solve(int n, int row, vector<int> &a, vector<vector<string>> &vec){
		if (row == n){
			vector<string> cur(n, string(n, '.'));
			for (int i = 0; i < n; i++){
				cur[i][a[i]] = 'Q';
			}
			vec.push_back(cur);
		}
		else if (row < n && a[row]==-1){
			for (int i = 0; i < n; i++){
				if (coexist(row, i, a)){
					a[row] = i;
					solve(n, row + 1, a, vec);
					a[row] = -1;
				}
			}
		}
	}
	bool coexist(int row, int col, const vector<int> &a){
		if (a[row] != -1)
			return false;
		for (int i = 0; i < a.size(); i++){
			if (a[i] != -1){
				int x = i - row;
				int y = a[i] - col;
				if (a[i]==col || x == y || x == -y){
					return false;
				}
			}
		}
		return true;
	}
	
	void test(){
		vector<int> a = { 1, 3, 0, -1 };
		cout << coexist(3,2,a) << endl;
		Utils::print(solveNQueens(4));
	}
};