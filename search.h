#include"utils.h"
class Solution {
	/**
	* param A : an integer ratated sorted array and duplicates are allowed
	* param target :  an integer to be search
	* return : a boolean
	*/
public:
	int search(vector<int> &A, int target) {
		if (A.size() == 0)
			return -1;
		int mid = findMin(A);
		int left = searchBinary(A, 0, mid - 1, target);
		int right = searchBinary(A, mid, A.size() - 1, target);
		return left == -1 ? right : left;
	}
	int searchBinary(vector<int> &num, int start, int end, int target){
		int left = start, right = end;
		while (left <= right){
			int mid = (left + right) / 2;
			if (num[mid] == target)
				return mid;
			else if (num[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
	int findMin(vector<int> &num) {
		int left = 0, right = num.size() - 1;
		if (num[left] < num[right])
			return left;
		while (left < right){
			int mid = (left + right) / 2;
			if (num[mid]>num[right])
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
	int findMinII(vector<int> &num) {
		int left = 0, right = num.size() - 1;
		if (num[left] < num[right])
			return left;
		while (left < right){
			int mid = (left + right) / 2;
			if (num[mid]>=num[right])
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
	//没使用二分法，时间复杂度略高
	bool searchII1(vector<int> &A, int target) {
		for (int i = 0; i < A.size(); i++){
			if (A[i] == target)   
				return true;
		}
		return false;
	 }
	bool searchII(vector<int> &A, int target) {
		if (A.size() == 0)
			return false;
		int mid = findMinII(A);
		cout << mid << endl;
		int left = searchBinary(A, 0, mid - 1, target);
		int right = searchBinary(A, mid, A.size() - 1, target);
		return left != -1 || right != -1;
	}
	void test(){
		vector<int> vec = { 4, 4, 4, 5, 1, 4 };
		cout << searchII(vec, 5) << endl;
	}
};