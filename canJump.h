#include"utils.h"
#include<algorithm>
class Solution {
public:
	int jump(vector<int> A) {
		//仍然超时
		int m = 0;
		int i = 0;
		vector<int> step(A.size());
		for (int i = 1; i < A.size(); i++){
			for (int j = 0; j < i; j++){
				if (j + A[j] >= i){
					step[i] += step[j] + 1;
					break;
				}
			}
		}
		return step[A.size() - 1];
	}
	int jump2(vector<int> A) {
		//仍然超时
		int m = 0;
		int i = 0;
		vector<int> step(A.size(), -1);
		step[0] = 0;
		while (i <= m && i<A.size()){
			m = max(A[i] + i, m);
			for (int j = i + 1; j <= m && j < A.size(); j++){
				if (step[j] == -1)
					step[j] = step[i] + 1;
				else
					step[j] = min(step[i] + 1, step[j]);
			}
			i++;
		}
		return step[A.size()-1];
	}
	int jump1(vector<int> A) {
		//运行超时，时间复杂度过高
		int len = A.size();
		int *step = new int[len];
		fill(step, step + len, -1);
		step[0] = 0;
		for (int i = 1; i < len; i++){
			for (int j = 0; j < i; j++){
				if (step[j]!=-1 && A[j] >= i - j){
					if (step[i] == -1)
						step[i] = step[j] + 1;
					else
						step[i] = min(step[i], step[j] + 1);
				}
			}
		}
		int ret = step[len - 1];
		delete []step;
		return ret;
	}
	bool canJump(vector<int> A) {
		//贪心算法,时间复杂度O(n)
		int m = 0;
		int i = 0;
		while (i <= m){
			m = max(A[i] + i, m);
			i++;
			if (m >= A.size())
				return true;
		}
		return false;
	}
	bool canJump1(vector<int> A) {
		//动态规划，时间复杂度O(n^2)
		int len = A.size();
		bool *dp = new bool[len];
		fill(dp, dp + len, false);
		dp[0] = true;
		for (int i = 1; i < len; i++){
			for (int j = 0; j < i; j++){
				if (dp[j] && A[j] >= i - j){
					dp[i] = true;
					break;
				}
			}
		}
		bool ret = dp[len - 1];
		delete []dp;
		return ret;
	}
	void test(){
		int a[] = { 2, 3, 1, 1, 4 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << jump(vec) << endl;
	}
};
