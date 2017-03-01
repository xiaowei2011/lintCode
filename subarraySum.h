#include<iostream>
#include<vector>
#include<algorithm>
#include"utils.h"
using namespace std;
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers includes the index of the first number
	*          and the index of the last number
	*/
	vector<int> subarraySum1(vector<int> nums){
		//时间复杂度为n^2运行超时
		int *sum = new int[nums.size()];
		sum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			sum[i] = sum[i - 1] + nums[i];
		Utils::print(sum, nums.size());
		int start = 0, end = 0;
		vector<int> sub;
		for (int j = 0; j < nums.size(); j++){
			if (sum[j] == 0){
				start = 0;
				end = j;
				break;
			}
			for (int i = 0; i < j; i++)
			{
				if (sum[i] == sum[j])
				{
					start = i+1;
					end = j;
					sub.push_back(start);
					sub.push_back(end);
					return sub;
				}
			}
		}
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	vector<int> subarraySum(vector<int> nums){
		pair<int, int> *sum = new pair<int, int>[nums.size() + 1];
		int s = 0;
		sum[0].first = 0;
		sum[0].second = 0;
		for (int i = 1; i <= nums.size(); i++){
			s += nums[i - 1];
			sum[i].first = s;
			sum[i].second = i;
		}
		//Utils::print(sum, nums.size() + 1);
		int start = 0, end = 0;
		sort(sum, sum + nums.size() + 1);
		//Utils::print(sum, nums.size() + 1);
		for (int i = 1; i <= nums.size(); i++){
			if (sum[i].first == sum[i - 1].first){
				start = min(sum[i].second, sum[i - 1].second);
				end = max(sum[i].second, sum[i - 1].second)-1;
			}
		}
		vector<int> sub;
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	void test(){
		int a[] = { -5, 10, 5, -3, 1, 1, 1, -2, 3, -4 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		Utils::print(vec);
		Utils::print(subarraySum1(vec));
	}
};