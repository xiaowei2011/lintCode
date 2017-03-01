#include"utils.h"
#include<algorithm>
class Solution {
public:
	
	int findMin(vector<int> &num) {
		int left = 0, right = num.size() - 1;
		if (num[left] < num[right])
			return num[left];
		while (left < right){
			int mid = (left + right) / 2;
			if (num[mid]>num[right])
				left = mid + 1;
			else
				right = mid;
		}
		return num[left];
	}

	int findMinII(vector<int> &num) {
		int left = 0, right = num.size() - 1;
		if (num[left] < num[right])
			return num[left];
		while (left < right){
			int mid = (left + right) / 2;
			if (num[mid]>=num[right])
				left = mid + 1;
			else
				right = mid;
		}
		return num[left];
	}
	
	int findMin1(vector<int> &num) {
		//时间复杂度为n,不满足要求
		return *min_element(num.begin(), num.end());
	}
	void test(){
		vector<int> vec = { 999, 999, 1000, 1000, 10000, 0, 999, 999, 999 };
		cout << findMinII(vec)<<endl;
	}
};