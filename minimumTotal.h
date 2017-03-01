#include"utils.h"
#include<algorithm>
class Solution {
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal1(vector<vector<int>> &triangle) {
		vector<vector<int>> dp(triangle.begin(), triangle.end());
		for (int i = 1; i < triangle.size(); i++){
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			for (int j = 1; j < triangle[i].size()-1; j++){
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
			dp[i][triangle[i].size() - 1] = dp[i - 1][dp[i - 1].size() - 1] +
				triangle[i][triangle[i].size() - 1];
		}
		return *min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
	}
	//不用遍历dp最底层，但可读性略差
	int minimumTotal2(vector<vector<int>> &triangle) {
		vector<vector<int>> dp(triangle.begin(), triangle.end());
		int ret = dp[dp.size() - 1][0];
		for (int i = 1; i < triangle.size(); i++){
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			if (i == triangle.size() - 1)
				ret = dp[i][0];
			for (int j = 1; j < triangle[i].size() - 1; j++){
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
				if (i == triangle.size() - 1 && dp[i][j]<ret)
					ret = dp[i][j];
			}
			dp[i][triangle[i].size() - 1] = dp[i - 1][dp[i - 1].size() - 1] +
				triangle[i][triangle[i].size() - 1];
			if (i == triangle.size() - 1 && dp[i][triangle[i].size() - 1] < ret)
				ret = dp[i][triangle[i].size() - 1];
		}
		return ret;
	}
	int minimumTotal3(vector<vector<int>> &triangle) {
		vector<int> dp;
		dp.push_back(triangle[0][0]);
		for (int i = 1; i < triangle.size(); i++){
			vector<int> temp = dp;
			dp[0] = temp[0] + triangle[i][0];
			for (int j = 1; j < dp.size(); j++){
				dp[j] = min(temp[j-1], dp[j]) + triangle[i][j];   
			}
			dp.push_back(temp.back() + triangle[i].back());
		}
		return *min_element(dp.begin(), dp.end());
	}
	//从后向前
	int minimumTotal4(vector<vector<int>> &triangle) {
		vector<int> dp(triangle.size());
		dp[0]=triangle[0][0];
		for (int i = 1; i < triangle.size(); i++){
			for (int j = i;j>=0; j--){
				int l = max(0, j - 1);
				int h = min(j, i - 1);
				dp[j] = min(dp[l], dp[h]) + triangle[i][j];
			}
		}
		return *min_element(dp.begin(), dp.end());
	}
	//自底向上
	int minimumTotal(vector<vector<int>> &triangle) {
		for (int i = triangle.size()-2; i >=0; i--){
			for (int j = 0; j <=i; j++){
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
	void test(){
		vector<vector<int>> vec = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
		cout << minimumTotal(vec) << endl;
		vector<vector<int>> vec2 = { { -1 }, { 2, 3 }, { 1, -1, -3 } };
		cout << minimumTotal(vec2) << endl;
	}
};