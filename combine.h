#include"utils.h"
class Solution {
public:
	vector<int> cur;
	vector<bool> used;
	vector<vector<int>> combine(int n, int k) {
		vector<int> arr;
		for (int i = 0; i < n; i++)
			arr.push_back(i + 1);
		cur.resize(k);
		used.resize(n);
		vector<vector<int>> ret;
		booktrace(ret, n, k, 0);
		return ret;
	}
	void booktrace(vector<vector<int>> &vec,int n,int k,int i){
		if (i == k){
			vec.push_back(cur);
		}
		else{
			for (int j = i; j <n; j++){
				if (!used[j]){
					used[j] = true;
					cur[i] = j+1;
					booktrace(vec,n,k,i + 1);
					used[j] = false;
				}
			}
		}
	}
	void test(){
		Utils::print(combine(4, 2));
	}
};