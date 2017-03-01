#include"utils.h"
class Solution {
public:

	/**
	* @param chars: The letters array you should sort.
	*/

	void sortLetters(string &letters) {
		vector<int> vec('z' - 'A');
		for (int i = 0; i < letters.size(); i++){
			vec[letters[i] - 'A']++;
		}
	}
};
