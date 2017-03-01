#include<iostream>
#include<vector>
#include"utils.h"
using namespace std;
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer denotes the sum of max two non-overlapping subarrays
	*/
	int maxTwoSubArrays(vector<int> nums){
		int len = nums.size();
		int *left = new int[len];
		left[0] = nums[0];
		int *right = new int[len];
		right[len - 1] = nums[len - 1];
		int sum = nums[0];
		int max = sum;
		for (int i = 1; i < len; i++){
			if (sum < 0){
				sum = nums[i];
			}
			else{
				sum += nums[i];
			}
			if (sum > max){
				max=sum;
			}
			left[i] = max;
		}
		sum = nums[len - 1];
		max = sum;
		for (int i = len - 2; i >= 0; i--){
			if (sum < 0){
				sum = nums[i];
			}
			else{
				sum += nums[i];
			}
			if (sum>max){
				max = sum;
			}
			right[i] = max;
		}
		max = INT_MIN;
		for (int i = 0; i < len - 1; i++){
			sum = left[i] + right[i+1];
			max = max < sum ? sum : max;
		}
		return max;
	}
	int maxTwoSubArrays2(vector<int> nums){
		//时间复杂度为n*n，但运行竟然通过了***
		int len = nums.size();
		int *left = new int[len];
		left[0] = nums[0];
		int *right = new int[len];
		right[len - 1] = nums[len - 1];
		int sum = nums[0];
		int max = sum;
		for (int i = 1; i < len; i++){
			if (sum < 0){
				sum = nums[i];
			}
			else{
				sum += nums[i];
			}
			left[i] = sum;
			if (max < sum){
				max = sum;
			}
		}
		sum = nums[len - 1];
		max = sum;
		for (int i = len - 2; i >= 0; i--){
			if (sum < 0){
				sum = nums[i];
			}
			else{
				sum += nums[i];
			}
			right[i] = sum;
			if (max < sum){
				max = sum;
			}
		}
		max = INT_MIN;
		for (int i = 0; i < len-1; i++){
			sum = getMax(left, 0, i+1) + getMax(right, i + 1, len);
			cout << getMax(left, 0, i + 1) << "<-->" << getMax(right, i + 1, len) << endl;
			max = max < sum ? sum : max;
		}
		return max;
	}
	int getMax(int nums[],int start,int end){
		int max = INT_MIN;
		for (int i = start; i < end; i++){
			if (max < nums[i]){
				max = nums[i];
			}
		}
		return max;
	}
	void test(){
		int a[] = { -1, -2, -3, -100, -1, -50 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << maxTwoSubArrays(vec)<< endl;
	}
	int maxTwoSubArrays1(vector<int> nums) {
		//运行超时
		int max = INT_MIN;
		for (int i = 1; i < nums.size(); i++){
			int s1 = maxSubArray(nums, 0, i);
			int s2 = maxSubArray(nums, i, nums.size());
			if (max < (s1 + s2)){
				max = s1 + s2;
			}
		}
		return max;
	}
	int maxSubArray(vector<int> nums,int start,int end) {
		int ps = nums[start];
		int ms = ps;
		for (int i = start+1; i <end; i++){
			if (ps > 0){
				ps = ps + nums[i];
			}
			else{
				ps = nums[i];
			}
			if (ps>ms){
				ms = ps;
			}
		}
		return ms;
	}
};
