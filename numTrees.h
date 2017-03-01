#include"utils.h"
class Solution {
public:
	
	int numTrees(int n) {
		int *dp = new int[n + 1];
		fill(dp, dp + n + 1, 0);
		Utils::print(dp, n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i < n+1; i++){
			for (int j = 1; j <= i; j++){
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		int ret = dp[n];
		delete []dp;
		return ret;
	}
	void test(){
		cout << numTrees(4) << endl;
	}
};