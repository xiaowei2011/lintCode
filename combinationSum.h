#include"utils.h"
#include<set>
#include<algorithm>
class Solution {
public:
	vector<vector<int> > combinationSumII(vector<int> &num, int target) {
		vector<int> cur;
		set<vector<int>> ss;
		sort(num.begin(), num.end());
		backtraceII(num, ss, cur, target, 0);
		vector<vector<int>> ret(ss.begin(),ss.end());
		return ret;
	}
	void backtraceII(vector<int> &num, set<vector<int>> &ss, vector<int> &cur,
		int left, int id){
		if (left == 0){
			ss.insert(cur);
			return;
		}
		for (int i = id; i < num.size(); i++){
			if (num[i] <= left){
				cur.push_back(num[i]);
				backtraceII(num, ss, cur, left - num[i], i + 1);
				cur.pop_back();
			}
			else
				break;
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> cur;
		set<vector<int>> ss;
		sort(candidates.begin(), candidates.end());
		backtrace(candidates, ss, cur, target, 0);
		vector<vector<int>> ret(ss.begin(), ss.end());
		return ret;
	}
	void backtrace(vector<int> &candidates, set<vector<int>> &ss, vector<int> &cur, int left, int id){
		if (left == 0){
			ss.insert(cur);
			return;
		}
		for (int i = id; i < candidates.size(); i++){
			if (candidates[i] <= left){
				cur.push_back(candidates[i]);
				backtrace(candidates, ss, cur, left - candidates[i], i);
				cur.pop_back();
			}
			else
				break;
		}
	}
	vector<vector<int> > combinationSum1(vector<int> &candidates, int target) {
		set<vector<int>> s;
		vector<int> cur;
		sort(candidates.begin(), candidates.end());
		combinationSum(candidates, target, s, cur, 0, 0);
		vector<vector<int>> ret(s.begin(), s.end());
		return ret;
	}
	void combinationSum(const vector<int> &candidates, int target, set<vector<int>> &s,
		vector<int> cur, int sum, int id){
		if (sum == target){
			s.insert(cur);
		}
		if (sum > target || id >= candidates.size())
			return;
		int sum1 = sum;
		vector<int> cur1 = cur;
		while (sum < target){
			sum += candidates[id];
			cur1.push_back(candidates[id]);
			combinationSum(candidates, target, s, cur1, sum, id);
		}
		sum = sum1;
		combinationSum(candidates, target, s, cur, sum, id + 1);
	}
	void test(){
		int a[] = { 2, 3, 6, 7 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		Utils::print(combinationSumII(vec, 7));
	}
};