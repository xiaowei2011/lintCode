#include<iostream>
#include<vector>
#include<algorithm>
#include"utils.h"
using namespace std;
class Solution {
public:
	/**
	* @param A : An integer array
	* @return : An integer
	*/
	int singleNumberII(vector<int> &A) {
		int bit[32]{0};
		for (auto x : A){
			for (int i = 0; i < 32; i++){
				if ((1 << i) & x){
					bit[31-i]=(bit[31-i]+1)%3;
				}
			}
		}
		int x = 0;
		for (int i = 0; i < 32; i++){
			x=(x<<1)+bit[i];
		}
		return x;
	}
	int singleNumberII1(vector<int> &A) {
		//时间复杂度过高，题目要求一次遍历
		sort(A.begin(), A.end());
		int n = 0;
		for (int i = 0; i + 2< A.size(); i+=3){
			if (A[i] != A[i + 2]){
				return A[i];
			}
		}
		return A.back();
	}
	void test(){
		int a[] = { 1, 1, 2, 3, 4, 4, 2, 2, 4, 1 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		int n = singleNumberII(vec);
		cout << n << endl;
	}
};