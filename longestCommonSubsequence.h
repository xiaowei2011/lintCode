#include"utils.h"
#include<algorithm>
class Solution {
public:
	/**
	* @param A, B: Two strings.
	* @return: The length of longest common subsequence of A and B.
	*/
	int longestCommonSubsequence(string A, string B) {
		vector<int> dp(B.size()+1);
		int m = 0;
		for (int i = 1; i <= A.size(); i++){
			vector<int> temp = dp;
			for (int j = 1; j <= B.size(); j++){
				if (A[i-1] == B[j-1]){
					dp[j] = temp[j - 1] + 1;
				}
				else{
					dp[j] = max(temp[j], dp[j - 1]);
				}
				if (dp[j] > m)
					m = dp[j];
			}
			Utils::print(dp);
		}
		return m;
	}
	void test(){
		string a = "bedaacbade";
		string b = "dccaeedbeb";
		cout << longestCommonSubsequence(a, b) << endl;
	}
};
