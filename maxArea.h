#include"utils.h"
class Solution {
public:
	/**
	* @param heights: a vector of integers
	* @return: an integer
	*/
	int maxArea(vector<int> &heights) {
		if (heights.size() < 2)
			return 0;
		int ret = 0;
		for (unsigned int i = 0, j = heights.size() - 1; i < j;){
			int area = min(heights[i], heights[j])*(j - i);
			ret = max(ret, area);
			heights[i] < heights[j] ? i++ : j--;
		}
		return ret;
	}

	void test(){
		vector<int> vec = { 1, 3, 2 };
		cout << maxArea(vec) << endl;
	}
};