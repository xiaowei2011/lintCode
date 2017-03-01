#include<iostream>
#include<vector>
#include<map>
#include"utils.h"
using namespace std;
class Solution {
public:
	int majorityNumberIII(vector<int> nums, int k) {
		//时间复杂度为O(n*k)，不满足要求
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++){
			if (m.find(nums[i]) == m.end()){
				m[nums[i]] = 1;
				if (m.size() == k){
					for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
						it->second--;
					}
				}
				for (map<int, int>::iterator it = m.begin(); it != m.end();){
					if (it->second == 0){
						m.erase(it++);
					}
					else{
						it++;
					}
				}
			}
			else{
				m[nums[i]]++;
			}
		}
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
			int count = 0;
			for (int i = 0; i < nums.size(); i++){
				if (it->first == nums[i]){
					count++;
				}
			}
			if (count > nums.size() / k){
				return it->first;
			}
		}
		return 0;
	}
	int majorityNumberIII2(vector<int> nums, int k) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++){
			if (m.find(nums[i]) == m.end()){
				m[nums[i]] = 1;
			}
			else{
				m[nums[i]]++;
			}
		}
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
			if (it->second > nums.size() / k)
				return it->first;
		}
		return 0;
	}
	int majorityNumberII(vector<int> nums) {
		int x, y, cnx = 0, cny = 0;
		for (int i = 0; i < nums.size(); i++){
			if (cnx == 0){
				x = nums[i];
				cnx = 1;
			}
			else if (cny == 0 && nums[i] != x){
				y = nums[i];
				cny = 1;
			}
			else{
				if (nums[i] == x)
					cnx++;
				else if (nums[i] == y)
					cny++;
				else{
					cnx--;
					cny--;
				}
			}
		}
		return cnx > 0 ? x : y;
	}
	int majorityNumberII2(vector<int> nums) {
		for (int i = 0; i < nums.size(); i++){
			int count = 0;
			for (int j = 0; j < nums.size(); j++){
				if (nums[j] == nums[i]){
					count++;
				}
			}
			if (count > nums.size() / 3)
				return nums[i];

		}
		return 0;
	}
	int majorityNumber(vector<int> nums) {
		int x, cnt = 0;
		for (int i = 0; i != nums.size(); ++i){
			if (cnt == 0)
				x = nums[i], cnt = 1;
			else
				nums[i] == x ? ++cnt : --cnt;
		}
		return x;
	}
	void test(){
		int a[] = { 7, 3, 1, 4, 5, 6, 17, 8, 9, 1 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		Utils::print(vec);
		cout << majorityNumberIII(vec, 10) << endl;
		//test1();
	}
	void test1(){
		map<string, string> mapData;
		mapData["a"] = "aaa";
		mapData["b"] = "bbb";
		mapData["c"] = "ccc";
		for (map<string, string>::iterator i = mapData.begin(); i != mapData.end();)
		{
			if (i->first == "b")
			{
				map<string, string>::iterator ti = i++;
				mapData.erase(ti);
			}
			else{
				i++;
			}
		}
	}
};
