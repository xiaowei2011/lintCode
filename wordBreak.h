#include"utils.h"
#include<unordered_set>
class Solution {
public:
	/**
	* @param s: A string s
	* @param dict: A dictionary of words dict
	*/
	bool wordBreak1(string s, unordered_set<string> &dict) {
		if (dict.find(s) != dict.end()) return true;
		for (int i = 1; i < dict.size(); i++){
			if (wordBreak(s.substr(0, i), dict) && wordBreak(s.substr(i), dict))
				return true;
		}
		return false;
	}
	bool wordBreak(string s, unordered_set<string> &dict) {
		int n = s.size();
		if (n == 0) return true;
		int maxLen = 0;
		for (const string& word : dict){
			maxLen = word.size() > maxLen ? word.size() : maxLen;
		}
		vector<bool> dp(n + 1);
		dp[0] = true;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i && j <= maxLen; j++){
				if (dp[i - j] && dict.find(s.substr(i - j, j)) != dict.end()){
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
	void test(){
		string s = "a";
		unordered_set<string> dict = { "a" };
		cout << wordBreak(s, dict) << endl;
	}
};
