#include"utils.h"
#include<cmath>
class Solution {
public:
	/**
	* @param n a positive integer
	* @return an integer
	*/
	//运行超时
	int numSquares1(int n) {
		vector<int> dp(n+1);
		dp[0] = dp[1] = 1;
		for (int i = 2; i < dp.size(); i++){
			dp[i] = i;
			int j = 2;
			while (j*j < i){
				j++;
			}
			if (j*j == i){
				dp[i] = 1;
				continue;
			}
			for (j = 1; j <= i/2; j++){
				dp[i] = min(dp[i], dp[i - j] + dp[j]);
			}
		}
		return dp[n];
	}

	int numSquares(int n) {
		//一神奇算法
		vector<int> dp(n + 1,n);
		for (int i = 0; i*i <= n;i++){
			dp[i*i] = 1;
		}
		for (int i = 0; i <= n; i++){
			for (int j = 0; i + j*j <= n; j++){
				dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
			}
		}
		return dp[n];
	}
	void test(){
		cout << numSquares(13) << endl;
	}
};