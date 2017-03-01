#include"utils.h"
#include<stack>
class Solution {
public:
	/**
	* @param nums: The integer array
	* @return: The length of LIS (longest increasing subsequence)
	*/
	int longestIncreasingSubsequence1(vector<int> nums) {
		if (nums.empty())
			return 0;
		vector<int> dp(nums.size(),1);
		for (int i = 1; i < dp.size(); i++){
			for (int j = 0; j < i; j++){
				if (nums[i] > nums[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}

	//时间复杂度降为O(NlogN)
	int longestIncreasingSubsequence(vector<int> nums) {
		if (nums.empty())
			return 0;
		vector<int> vec;
		vec.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] > vec.back()){
				vec.push_back(nums[i]);
			}
			else{
				*upper_bound(vec.begin(), vec.end(),nums[i])=nums[i];
			}
		}
		return vec.size();
	}
	void test(){
		vector<int> vec = { 5, 4, 1, 2, 3,1,4 };
		cout << longestIncreasingSubsequence(vec) << endl;
	}
};
