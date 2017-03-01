#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minimumSize(vector<int> &nums, int s) {
		int minLen = INT_MAX;
		int start = 0, end = 0, sum = 0;
		while (end < nums.size()){
			sum += nums[end];
			if (sum >= s){
				minLen = minLen <= (end - start + 1) ? minLen : (end - start + 1);
				while (sum >= s && start <= end){
					minLen = minLen <= (end - start + 1) ? minLen : (end - start + 1);
					sum -= nums[start];
					start++;
				}
			}
			end++;
		}
		if (minLen == INT_MAX){
			minLen = -1;
		}
		return minLen;
	}
	int minimumSize1(vector<int> &nums, int s) {
		bool *used =new bool[nums.size()]{0};
		int sum = 0, count = 0, i = 0;
		while (sum < s && i<nums.size()){
			int id = max(nums, used);
			cout << id << endl;
			used[id] = true;
			sum += nums[id];
			count++;
			i++;
		}
		return count;
	}
	int max(const vector<int> &nums, bool used[]){
		int id = 0;
		int max = INT_MIN;
		for (int i = 0; i < nums.size(); i++){
			if (!used[i] && nums[i]>max){
				max = nums[i];
				id = i;
			}
		}
		return id;
	}
	void test(){
		int a[] = { 2, 3, 1, 2, 4, 3 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << "m:" << minimumSize(vec, 7) << endl;
	}
	void test1(){
		int *a = new int[]{ 2, 3, 1, 2, 4, 3 };
		cout << "sizeof(a):" << sizeof(a) << endl;
		for (int i = 0; i < 6; i++){
			cout << a[i] << endl;
		}
	}
};