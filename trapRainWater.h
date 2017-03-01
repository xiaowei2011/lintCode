#include"utils.h"
#include<algorithm>
class Solution {
public:
	/**
	* @param heights: a vector of integers
	* @return: a integer
	*/
	//写的略烦
	int trapRainWater1(vector<int> &heights) {
		if (heights.size() < 3)
			return 0;
		vector<int> he(heights.size());
		int rain = 0;
		int high = 0;
		for (int i = 0, j = heights.size()-1; i < j;){
			int h = min(heights[i], heights[j]);
			rain += max(0, h - high)*(j - i + 1);
			//cout << i << " " << j << " -- " << h << ":" << rain << endl;
			high = max(high, h);
			he[i] = he[j] = high;
			if (heights[i] < heights[j])
				i++;
			else
				j--;
		}
		//Utils::print(he);
		for (int i = 0; i < heights.size(); i++){
			rain -= min(heights[i], he[i]);
			//cout << rain << ":" << he[i] << endl;
		}
		return rain;
	}
	//简化之
	//要求O(1)的空间复杂度，不满足
	int trapRainWater2(vector<int> &heights) {
		if (heights.size() < 3)
			return 0;
		vector<int> he(heights.size());
		int last = 0;
		for (int i = 0, j = heights.size() - 1; i < j;){
			int h = min(heights[i], heights[j]);
			last = max(last, h);
			he[i] = he[j] = last;
			if (heights[i] < heights[j])
				i++;
			else
				j--;
		}
		int rain = 0;
		for (int i = 0; i < heights.size(); i++){
			rain += max(0, he[i] - heights[i]);
		}
		return rain;
	}
	//进一步简化，成功将空间复杂度降到了O(1)
	int trapRainWater(vector<int> &heights) {
		if (heights.size() < 3)
			return 0;
		int rain = 0;
		int last = 0;
		for (int i = 0, j = heights.size() - 1; i < j;){
			if (heights[i] < heights[j]){
				last = max(last, heights[i]);
				rain += max(0, last - heights[i]);
				i++;
			}
			else{
				last = max(last, heights[j]);
				rain += max(0, last - heights[j]);
				j--;
			}
		}
		return rain;
	}
	void test(){
		vector<int> vec = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
		cout << trapRainWater(vec) << endl;
	}
};