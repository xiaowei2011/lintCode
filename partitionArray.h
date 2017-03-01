#include"utils.h"
class Solution {
public:
	int partitionArray(vector<int> &nums, int k) {
		int p = 0;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] < k){
				swap(nums[i], nums[p]);
				p++;
			}
		}
		return p;
	}
	int partitionArray2(vector<int> &nums, int k) {
		int key = INT_MIN;
		int kid = -1;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] >= k && nums[i] - k < key - k){
				key = nums[i];
				kid = i;
			}
		}
		if (key == INT_MIN)
			return nums.size();
		cout << k << "-" << kid << endl;
		cin.get();
		int i = 0, j = nums.size() - 1;
		while (i < j){
			cout << i <<":"<< j << endl;
			while (i<j && nums[i] <= key){
				i++;
			}
			swap(nums[i], nums[kid]);
			kid = i;
			while (i<j && nums[j] >= key){
				j--;
			}
			swap(nums[j], nums[kid]);
			kid = j;
		}
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] == nums[kid] && i < kid){
				kid = i;
				break;
			}
		}
		return kid;
	}
	void test(){
		int a[] = { 9, 9, 9, 8, 9, 8, 7, 9, 8, 8, 8, 9, 8, 9, 8, 8, 6, 9 };
		vector<int> vec(a,a+sizeof(a)/sizeof(int));
		int num = 9;
		cout << partitionArray(vec, num) << endl;
	}
};