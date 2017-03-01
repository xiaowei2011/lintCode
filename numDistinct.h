#include"utils.h"
class Solution {
public:
	/**
	* @param S, T: Two string.
	* @return: Count the number of distinct subsequences
	*/
	int numDistinct1(string &S, string &T) {
		if (T.size() == 0) return 1;
		if (S == T) return 1;
		if (S.size() <= T.size()) return 0;
		int count = 0;
		for (int i = 0; i < S.size(); i++){
			string s = S;
			s.erase(i,1);
			count += numDistinct1(s, T);
		}
		return count;
	}
	int numDistinct(string &S, string &T) {
		
	}
	void test(){
		string s = "rabbbit";
		string t = "rabbit";
		cout << numDistinct(s, t) << endl;
	}
};