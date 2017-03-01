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

	vector<int> subarraySumClosest(vector<int> nums){
		vector<pair<int, int>> sum;
		int temp = 0;
		sum.push_back(make_pair(temp, -1));
		for (int i = 0; i<nums.size(); i++)
		{
			temp += nums[i];
			sum.push_back(make_pair(temp, i));
		}
		sort(sum.begin(), sum.end());
		int start, end;
		int diff = INT_MAX;
		for (int i = 1; i<sum.size(); i++)
		{
			if (abs(sum[i].first - sum[i - 1].first) <= diff)
			{
				diff = abs(sum[i].first - sum[i - 1].first);
				start = min(sum[i].second, sum[i - 1].second) + 1;
				end = max(sum[i].second, sum[i - 1].second);
			}
		}
		vector<int> ret;
		ret.push_back(start);
		ret.push_back(end);
		return ret;
	}
	vector<int> subarraySumClosest2(vector<int> nums){
		//结果不对
		vector<int> sub;
		if (nums.size() < 2){
			sub.push_back(0);
			sub.push_back(0);
			return sub;
		}
		int ps = nums[0],pi=0;
		int ms = ps,start=0,end=0;
		for (int i = 1; i < nums.size(); i++){
			if ((ps > 0 && nums[i]<0) || (ps<0 && nums[i]>0)){
				ps = ps + nums[i];
			}
			else{
				ps = nums[i];
				pi = i;
			}
			if (getAbs(ps)<getAbs(ms)){
				ms = ps;
				start = pi;
				end = i;
			}
		}
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	vector<int> subarraySumClosest1(vector<int> nums){
		//时间复杂度过高，运行超时
		int max = INT_MAX;
		int start=0,end = 0;
		for (int i = 0; i < nums.size(); i++){
			for (int j = i; j < nums.size(); j++){
				int sum = 0;
				for (int k = i; k <= j; k++){
					sum += nums[k];
				}
				sum = getAbs(sum);
				if (sum < max){
					max = sum;
					start = i;
					end = j;
				}
			}
		}
		vector<int> sub;
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	void test(){
		int a[] = { 6, -4, -8, 3, 1, 7 };
		vector<int> vec(a,a+sizeof(a)/sizeof(int));
		Utils::print(vec);
		Utils::print(subarraySumClosest(vec));
		pair<int, int> p0(1,3),p1(5,2),p2(3,4),p3(2,1);
		pair<int, int> ps[4];
		ps[0] = p0;
		ps[1] = p1;
		ps[2] = p2;
		ps[3] = p3;
		vector<pair<int, int>> v(ps, ps + 4);
		Utils::print(ps, 4);
		sort(v.begin(),v.end());
		Utils::print(v);
		cout << "----" << endl;
		vector<vector<int>> v1(4,vector<int>(2,3));
		Utils::print(v1);
	}
	int getAbs(int n){
		return n < 0 ? -n : n;
	}
};
