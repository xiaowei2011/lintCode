#include<iostream>
#include<vector>
#include<algorithm>
#include"utils.h"
using namespace std;
class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: an integer
	*/
	int maxProduct(vector<int>& nums) {
		return 0;
	}
	int maxProduct1(vector<int>& nums) {
		//‘À––≥¨ ±
		int *pro = new int[nums.size()];
		int max = nums[0];
		for (int i = 0; i < nums.size(); i++){
			int p = 1;
			for (int j = i; j < nums.size(); j++){
				p *= nums[j];
				if (p > max){
					max = p;
				}
			}
		}
		return max;
	}
	void test(){
		int a[] = { 1, 0, -1, 2, 3, -5, -2 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << maxProduct(vec) << endl;
	}
};
