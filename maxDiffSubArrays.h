#include<iostream>
#include<vector>
#include<algorithm>
#include"utils.h"
using namespace std;
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer indicate the value of maximum difference between two
	*          Subarrays
	*/
	int maxDiffSubArrays(vector<int> nums) {
		int len = nums.size();
		int *left1 = new int[len];
		int *left2 = new int[len];
		left1[0] = nums[0];
		left2[0] = nums[0];
		int *right1 = new int[len];
		int *right2 = new int[len];
		right1[len - 1] = nums[len - 1];
		right2[len - 1] = nums[len - 1];
		int sum1 = nums[0], sum2 = nums[0];
		int max = sum1, min = sum2;
		for (int i = 1; i < len; i++){
			if (sum1 < 0){
				sum1 = nums[i];
			}
			else{
				sum1 += nums[i];
			}
			if (sum1 > max){
				max = sum1;
			}
			left1[i] = max;

			if (sum2 < 0){
				sum2 += nums[i];
			}
			else{
				sum2 = nums[i];
			}
			if (sum2 < min){
				min = sum2;
			}
			left2[i] = min;
		}
		sum1 = nums[len - 1];
		max = sum1;
		sum2 = nums[len - 1];
		min = sum2;
		for (int i = len - 2; i >= 0; i--){
			if (sum1 < 0){
				sum1 = nums[i];
			}
			else{
				sum1 += nums[i];
			}
			if (sum1 > max){
				max = sum1;
			}
			right1[i] = max;

			if (sum2 < 0){
				sum2 += nums[i];
			}
			else{
				sum2 = nums[i];
			}
			if (sum2 < min){
				min = sum2;
			}
			right2[i] = min;
		}
		int dif = 0;
		int result = 0;
		for (int i = 0; i < len - 1; i++){
			int dif1 = abs(left1[i] - right2[i + 1]);
			int dif2 = abs(left2[i] - right1[i + 1]);
			if (getMax(dif1, dif2) > result){
				result = getMax(dif1, dif2);
			}
		}
		return result;
	}
	void test(){
		int min = 1;
		int test = 2;
		int getMax = 1;
		//cout << getMax(1, 2) << endl;
	}
	int getMax(int a,int b){
		return a > b ? a : b;
	}
};
