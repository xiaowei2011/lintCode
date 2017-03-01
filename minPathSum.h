#include"utils.h"
#include<algorithm>
class Solution {
public:
	/**
	* @param grid: a list of lists of integers.
	* @return: An integer, minimizes the sum of all numbers along its path
	*/
	int minPathSum1(vector<vector<int>> &grid) {
		if (grid.size() < 1 || grid[0].size() < 1)
			return 0;
		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < grid[0].size(); i++){
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < grid.size(); i++){
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for (int i = 1; i < grid.size(); i++){
			for (int j = 1; j < grid[i].size(); j++){
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[dp.size() - 1][dp[0].size() - 1];
	}
	//空间复杂度从O(n^2）降到了O(n)
	int minPathSum(vector<vector<int>> &grid) {
		if (grid.size() < 1 || grid[0].size() < 1)
			return 0;
		int row = grid.size();
		int column = grid[0].size();
		vector<int> dp(column);
		dp[0] = grid[0][0];
		for (int i = 1; i < grid[0].size(); i++)
			dp[i] = dp[i - 1] + grid[0][i];
		//Utils::print(dp);
		for (int i = 1; i < grid.size(); i++){
			dp[0] += grid[i][0];
			for (int j = 1; j < grid[i].size(); j++){
				dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
			}
			//Utils::print(dp);
		}
		return dp[dp.size() - 1];
	}

	void test(){
		vector<int> v1 = { 1, 2 };
		vector<vector<int>> vec(2, v1);
		vec[1][1] = 1;
		Utils::print(vec);
		cout << minPathSum(vec) << endl;
	}
};
