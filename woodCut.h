#include"utils.h"
#include<algorithm>
class Solution {
public:
	
	int woodCut(vector<int> L, int k) {
		int low = 1;
		int high = *max_element(L.begin(), L.end());
		int id=search(L, low, high, k);
		return id;
	}
	int check(vector<int> &array,int length,int k){
		int count = 0;
		for (int i = 0; i < array.size(); i++){
			count += array[i] / length;
		}
		if (count < k)
			return -1;
		else if (count == k)
			return 0;
		else
			return 1;
	}
	int search(vector<int> &array, int start, int end, int k){
		int low = start, high = end;
		int ret = 0;
		while (low <= high){
			int mid = low + (high - low) / 2;
			int count = 0;
			for (int i = 0; i < array.size(); i++){
				count += array[i] / mid;
			}
			if (count >= k){
				ret = mid;
				low = mid + 1;
			}	
			else
				high = mid - 1;
		}
		return ret;
	}
	void test(){
		int a[] = { 2147483644, 2147483645, 2147483646, 2147483647 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << woodCut(vec, 4) << endl;
		cout << "---"<<endl<<*min_element(a,a+3) << endl<<*max_element(vec.begin(),vec.end())<<endl;
	}
};