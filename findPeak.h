#include"utils.h"
class Solution {
public:
	
	int findPeak(vector<int> A) {
		int left = 0, right = A.size() - 1;
		if (left >= right)
			return left;
		while (left <= right){
			int mid = (left + right) / 2;
			if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
				return mid;
			else if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return -1;
	}
	int findPeak1(vector<int> A) {
		//没用到二分法
		for (int i = 1; i < A.size()-1; i++){
			if (A[i] > A[i - 1] && A[i] > A[i + 1]){
				return i;
			}
		}
		return 0;
	}
};
