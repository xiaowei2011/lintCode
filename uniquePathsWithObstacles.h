#include"utils.h"
class Solution {
public:
	/**
	* @param obstacleGrid: A list of lists of integers
	* @return: An integer
	*/
	//运行出错
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {     
		vector<int> dp(obstacleGrid[0].size());
		dp[0] = !obstacleGrid[0][0];
		for (int i = 0; i < obstacleGrid.size(); i++){
			dp[0] = dp[0] && !obstacleGrid[i][0];
			for (int j = 1; j < obstacleGrid[i].size(); j++){
				if (obstacleGrid[i][j] == 1)
					dp[j] = 0;
				else
					dp[j] += dp[j - 1];
			}
		}
		return dp[dp.size() - 1];
	}
	//在原数组上操作
	int uniquePathsWithObstacles1(vector<vector<int>> &obstacleGrid) {
		obstacleGrid[0][0] = !obstacleGrid[0][0];
		for (int i = 1; i < obstacleGrid.size(); i++){
			obstacleGrid[i][0] = obstacleGrid[i][0] == 1 ? 0 : obstacleGrid[i - 1][0];
		}
		for (int i = 1; i < obstacleGrid[0].size(); i++){
			obstacleGrid[0][i] = obstacleGrid[0][i] == 1 ? 0 : obstacleGrid[0][i - 1];
		}
		for (int i = 1; i < obstacleGrid.size(); i++){
			for (int j = 1; j < obstacleGrid[i].size(); j++){
				obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
			}
		}
		return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size()-1];
	}
	void test(){
		vector<vector<int>> vec = { { 0, 0, 0, 0, }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 }, { 0, 0, 0, 0 } };
		Utils::print(vec);
		cout << uniquePathsWithObstacles1(vec) << endl;
		Utils::print(vec);
	}
};