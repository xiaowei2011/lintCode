#include"utils.h"
#include<algorithm>
class Solution {
	
public:
	vector<int> searchRange(vector<int> &A, int target) {
		int left = lower_bound(A.begin(), A.end(), target) - A.begin();
		int right = upper_bound(A.begin(), A.end(), target) - A.begin();
		if (left == right){
			left = -1;
			right = 0;
		}
		vector<int> ret;
		ret.push_back(left);
		ret.push_back(right-1);
		return ret;
	}
	vector<int> searchRange2(vector<int> &A, int target) {
		int left = 0, right = A.size() - 1;
		int id = -1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (A[mid] == target){
				id = mid;
				break;
			}
			else if (A[mid] < target){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		int start = -1,end=-1;
		if (id != -1){
			int i = id;
			while (i >= 0 && A[i] == A[id]){
				start = i;
				i--;
			}
			i = id;
			while (i < A.size() && A[i] == A[id]){
				end = i;
				i++;
			}
		}
		vector<int> ret;
		ret.push_back(start);
		ret.push_back(end);
		return ret;
	}
	vector<int> searchRange1(vector<int> &A, int target) {
		vector<int> ret;
		int start = -1, end = -1;
		for (int i = 0; i < A.size(); i++){
			if (A[i] == target){
				end = i;
				if (start==-1)
					start = i;
			}
		}
		ret.push_back(start);
		ret.push_back(end);
		return ret;
	}
	void test(){
		int a[] = {1};
		vector<int> vec;
		Utils::print(searchRange(vec, 9));
	}
};