#include"utils.h"
class Solution {
public:
	
	int uniquePaths(int m, int n) {
		vector<int> dp(n,1);
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				dp[j] +=dp[j-1];
			}
		}
		return dp[n-1];
	}
	int uniquePaths1(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){  
				int up = 0, left = 0;
				if (i != 0){
					up = dp[i - 1][j];
				}
				if (j != 0){
					left = dp[i][j - 1];
				}
				dp[i][j] = left + up;
			}
		}
		return dp[m - 1][n - 1];
	}
	void test(){
		for (int i = 1; i <= 20; i++){
			for (int j = 1; j <= 20; j++){
				cout << uniquePaths(i, j)<<" ";
			}
			cout << endl;
		}
	}
};
