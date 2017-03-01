#include<iostream>
#include<vector>
#include"utils.h"
using namespace std;
class Solution {
public:
	
	//在前i个数里面取了j段，这样dp[i][j] = max(dp[p][j - 1] + f(p + 1, i)), 
	//其中f(i，j)表示数组从i到j的最大子数组和，其中f可以通过预处理得到

	int maxSubArray(vector<int> nums, int k) {
		int len = nums.size();
		vector<vector<int>> dp(len+1, vector<int>(k+1,INT_MIN));
		for (int i = 0; i < len; i++){
			dp[i][0] = 0;
		}
		for (int i = 2; i <= len; i++){
			for (int j = 2; j <= k; j++){
				for (int p = 1; p < i; p++){
					int temp = dp[p][j - 1] + maxSubArray(nums, p + 1, i);
					dp[i][j] = temp > dp[i][j] ? temp : dp[i][j];
				}
			}
		}
		return dp[len][k];
	}
	void test(){
		int a[] = { 6, -4, -8, 3, 1, 7 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		Utils::print(vec);
		cout << maxSubArray(vec,2) << endl;
	}
	
	int maxSubArray(vector<int> nums,int start,int end) {
		int ps = nums[start];
		int ms = ps;
		for (int i = 1; i <= end; i++){
			if (ps > 0){
				ps = ps + nums[i];
			}
			else{
				ps = nums[i];
			}
			if (ps>ms){
				ms = ps;
			}
		}
		return ms;
	}
	int maxSubArray(vector<int> nums) {
		if (nums.size() < 1){
			return 0;
		}
		int ps = nums[0];
		int ms = ps;
		for (int i = 1; i < nums.size(); i++){
			if (ps > 0){
				ps = ps + nums[i];
			}
			else{
				ps = nums[i];
			}
			if (ps>ms){
				ms = ps;
			}
		}
		return ms;
	}
};