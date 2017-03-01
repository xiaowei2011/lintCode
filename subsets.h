#include"utils.h"
#include<list>
#include<queue>
#include<cmath>
class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	//�ռ临�Ӷȹ��ߣ�Memory Limit Exceeded
	vector<vector<int>> subsets1(vector<int> &nums) {
		queue<vector<int>> q;
		vector<vector<int>> vec;
		q.push(nums);
		int start = 0;
		for (int i = 0; i < nums.size(); i++){
			int len = q.size();
			while (len-- > 0){
				vector<int> temp1 = q.front();
				q.pop();
				vec.push_back(temp1);
				for (int j = 0; j < temp1.size(); j++){
					vector<int> temp2 = temp1;
					temp2.erase(temp2.begin() + j);
					q.push(temp2);
				}
			}
		}
		vec.push_back(vector<int>());
		set<vector<int>> s;
		for (auto &v : vec){
			s.insert(v);
		}
		vec.clear();
		for (auto &v : s){
			vec.push_back(v);
		}
		return vec;
	}
	//�����˿ռ����ģ���Time Limit Exceeded
	vector<vector<int>> subsets2(vector<int> &nums) {
		queue<vector<int>> q;
		set<vector<int>> s;
		q.push(nums);
		int start = 0;
		for (int i = 0; i < nums.size(); i++){
			int len = q.size();
			while (len-- > 0){
				vector<int> temp1 = q.front();
				q.pop();
				s.insert(temp1);
				for (int j = 0; j < temp1.size(); j++){
					vector<int> temp2 = temp1;
					temp2.erase(temp2.begin() + j);
					q.push(temp2);
				}
			}
		}
		s.insert(vector<int>());
		vector<vector<int>> vec;
		for (auto &v : s){
			vec.push_back(v);
		}
		return vec;
	}
	
	vector<vector<int>> subsets3(vector<int> &nums) {
		//�ݹ�ʵ��
		return subsets(nums,nums.size());
	}
	vector<vector<int>> subsets(vector<int> &nums,int end) {
		vector<vector<int>> vec;
		if (end == 0){
			vec.push_back(vector<int>());
			return vec;
		}
		vector<vector<int>> sub = subsets(nums, end - 1);
		vec.insert(vec.end(), sub.begin(), sub.end());
		for (int i=0; i < sub.size(); i++){
			sub[i].push_back(nums[end - 1]);
			vec.push_back(sub[i]);
		}
		return vec;
	}
	vector<vector<int>> subsets4(vector<int> &nums) {
		//�ǵݹ�ʵ��
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
		return vec;
	}
	//һ�����㷨
	//{1��2��3}���Ӽ��ֱ�Ϊ{000��001��010��011��100��101��110��111}��1����ѡ���λ�õ����֣�0����ѡ
	vector<vector<int>> subsets5(vector<int> &nums) {
		vector<vector<int>> vec;
		for (int i = 0; i < pow(2, nums.size()); i++){
			int temp = i;
			vector<int> v;
			for (int j = 0; j < nums.size(); j++){
				int bit = temp & 1;
				temp >>= 1;
				if (bit == 1){
					v.push_back(nums[j]);
				}
			}
			vec.push_back(v);
		}
		return vec;
	}
	vector<vector<int>> subsets6(vector<int> &nums) {
		//���ݷ�
		vector<vector<int>> vec;
		vector<int> base;
		backtracing1(nums, 0, nums.size(), base, vec);
		return vec;
	}
	void backtracing1(vector<int> &nums,int cur,int n,vector<int> &base,vector<vector<int>> &vec){
		cout << cur << " : ";
		Utils::print(base);
		if (cur == n){
			vec.push_back(base);
			return;
		}
		base.push_back(nums[cur]);
		backtracing1(nums, cur + 1, n, base, vec);
		base.pop_back();
		backtracing1(nums, cur + 1, n, base, vec);
	}
	vector<vector<int>> subsets7(vector<int> &nums) {
		//���ݷ�
		vector<vector<int>> vec;
		backtracing2(nums, 0, vector<int>(), vec);
		return vec;
	}
	void backtracing2(vector<int> &nums, int cur, vector<int> &base, vector<vector<int>> &vec){
		vec.push_back(base);
		for (int i = cur; i < nums.size(); i++){
			base.push_back(nums[i]);
			backtracing2(nums, i+1, base, vec);
			base.pop_back();
		}
	}
	void test(){
		vector<int> vec = { 1, 2, 2 };
		Utils::print(subsets7(vec));
	}
};