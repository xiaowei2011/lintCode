#include"utils.h"
class Solution {
public:
	/**
	* @param A, B: Two string.
	* @return: the length of the longest common substring.
	*/
	int longestCommonSubstring1(string &A, string &B) {
		vector<int> dp(B.size());
		int max = 0;
		for (int i = 0; i < A.size(); i++){
			vector<int> temp = dp;
			for (int j = 0; j < B.size(); j++){
				if ((i == 0 || j == 0) && A[i] == B[j]){
					dp[j] = 1;
				}
				else if (A[i] == B[j]){
					dp[j] = temp[j - 1] + 1;
				}
				else{
					dp[j] = 0;
				}
				if (dp[j] > max)
					max = dp[j];
			}
		}
		return max;
	}
	int longestCommonSubstring(string &A, string &B) {
		if (B.size()==0) return 0;
		if (A.find(B) != string::npos) return B.size();
		int m = 0;
		for (int i = 0; i < B.size(); i++){
			int len = max(longestCommonSubstring(A, B), longestCommonSubstring(A, B));
		}
	}
	void test(){
		string a = "abcd";
		string b = "cbce";
		cout << longestCommonSubstring(a, b)<<endl;
	}
};