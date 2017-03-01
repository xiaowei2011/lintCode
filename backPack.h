#include"utils.h"
#include<algorithm>
#include<numeric>
class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @return: The maximum size
	*/
	int backPack1(int m, vector<int> A) {
		int mw = 0;
		backtracing(m, A, 0, mw, 0);
		return mw;
	}
	void backtracing(int m, vector<int> &nums, int cur, int &mw, int w){
		if (cur == nums.size()){
			mw = max(mw, w);
		}
		else{
			if (w + nums[cur] <= m)
				backtracing(m, nums, cur + 1, mw, w + nums[cur]);
			backtracing(m, nums, cur + 1, mw, w);
		}
	}
	int backPack(int m, vector<int> A) {
		vector<int> dp(m + 1);
		for (int i = 0; i < A.size(); i++){
			for (int j = m; j >= A[i]; j--){
				dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
			}
		}
		return dp[dp.size() - 1];
	}
	int backPackII1(int m, vector<int> A, vector<int> V) {
		int maxValue = 0;
		backtracingII(m, A, V, 0, 0, 0, maxValue);
		return maxValue;
	}
	//回溯法，超时（剪枝不够）
	void backtracingII(int m, vector<int> &A, vector<int> &V, int cur, int weight, int value,int &maxValue){
		if (cur == A.size()){
			maxValue = max(maxValue, value);
		}
		else{
			if (weight + A[cur] <= m){
				backtracingII(m, A, V, cur + 1, weight + A[cur], value + V[cur], maxValue);
			}
			backtracingII(m, A, V, cur + 1, weight, value, maxValue);
		}
	}

	//动态规划
	int backPackII(int m, vector<int> A, vector<int> V) {
		vector<int> dp(m + 1);
		vector<vector<int>> vec(m + 1);
		for (int i = 0; i < A.size(); i++){
			for (int j = m; j >= A[i]; j--){
				dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
			}
		}
		return dp[dp.size() - 1];
	}
	
	int backPackVI(vector<int>& nums, int target) {
		vector<int> dp(target+1);
		vector<vector<int>> vec(target + 1);
		for (int i = 0; i < target+1; i++){
			for (int j = target; j >= nums[i]; j--){
				cout << i << ":" << j << endl;
				if (dp[j] < dp[j - nums[i]] + nums[i]){
					dp[j] = dp[j - nums[i]] + nums[i];
					vec[j] = vec[j - nums[i]];
					vec[j].push_back(nums[i]);
				}
			}
		}
		Utils::print(vec);
		return dp[dp.size() - 1];
	}
	//计算排列(nums已排序)
	int arrangement(vector<int> &nums){
		int count = 1;
		int same = 1;
		for (int i = 0; i < nums.size(); i++){
			if (i != 0 && nums[i] == nums[i - 1])
				same++;
			else
				same = 1;
			count *= (i + 1);
			count /= same;
		}
		return count;
	}
	
	void test(){
		vector<int> v1 = { 1,2,4 };
		cout <<backPackVI(v1,4) << endl;
	}
};