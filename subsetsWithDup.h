#include"utils.h"
class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int>> subsetsWithDup1(const vector<int> &S) {
		vector<int> nums = S;
		sort(nums.begin(), nums.end());
		vector<vector<int>> vec = subsetsWithDup(nums, nums.size());
		set<vector<int>> s(vec.begin(),vec.end());
		vec.assign(s.begin(), s.end());
		return vec;
	}
	vector<vector<int>> subsetsWithDup(const vector<int> &nums, int end) {
		vector<vector<int>> vec;
		if (end == 0){
			vec.push_back(vector<int>());
			return vec;
		}
		vector<vector<int>> sub = subsetsWithDup(nums, end - 1);
		vec.insert(vec.end(), sub.begin(), sub.end());
		for (int i = 0; i < sub.size(); i++){
			sub[i].push_back(nums[end - 1]);
			vec.push_back(sub[i]);
		}
		return vec;
	}
	vector<vector<int>> subsetsWithDup2(const vector<int> &S) {
		//·ÇµÝ¹é
		vector<int> nums = S;
		sort(nums.begin(), nums.end());
		vector<vector<int>> vec;
		vec.push_back(vector<int>());
		for (int i = 0; i < nums.size(); i++){
			int len = vec.size();
			for (int j = 0; j < len; j++){
				vector<int> temp = vec[j];
				temp.push_back(nums[i]);
				vec.push_back(temp);
			}
		}
		set<vector<int>> s(vec.begin(), vec.end());
		vec.assign(s.begin(), s.end());
		return vec;
	}
	vector<vector<int>> subsetsWithDup3(const vector<int> &S) {
		vector<int> nums = S;
		sort(nums.begin(), nums.end());
		vector<vector<int>> vec;
		vec.push_back(vector<int>());
		for (int i = 0; i < nums.size();){
			int len = vec.size();
			int j = i + 1;
			while (j < nums.size() && nums[j] == nums[i])
				j++;
			vector<int> temp1;
			j = j - i;
			while (j-- > 0){
				temp1.push_back(nums[i]);
				for (int k = 0; k < len; k++){
					vector<int> temp2 = vec[k];
					temp2.insert(temp2.end(),temp1.begin(),temp1.end());
					vec.push_back(temp2);
				}
				i++;
			}
		}
		return vec;
	}
	vector<vector<int>> subsetsWithDup(const vector<int> &S) {
		vector<vector<int>> vec;
		vector<int> nums(S), base;
		sort(nums.begin(), nums.end());
		backtracing(nums, 0, base, vec);
		return vec;
	}
	void backtracing(vector<int> nums,int cur,vector<int> &base,vector<vector<int>> &vec){
		vec.push_back(base);
		for (int i = cur; i < nums.size(); i++){
			if (i != cur && nums[i] == nums[i - 1])
				continue;
			base.push_back(nums[i]);
			backtracing(nums, i + 1, base, vec);
			base.pop_back();
		}
	}
	void test(){
		vector<int> vec = { 1, 2, 2 };
		Utils::print(subsetsWithDup(vec));
	}
};