#include<iostream>
#include<vector>
#include<algorithm>
#include"utils.h"
using namespace std;
class Solution {
public:
	/**
	* @param A: a vector of integers
	* @return: an integer
	*/
	int firstMissingPositive(vector<int> A) {
		for (int i = 0; i < A.size(); i++){
			while (A[i] != i + 1){
				if (A[i]>0 && A[i] <= A.size() && A[A[i] - 1] != A[i]){
					int temp = A[A[i] - 1];
					A[A[i] - 1] = A[i];
					A[i] = temp;
				}
				else{
					break;
				}
			}
		}
		for (int i = 0; i < A.size(); i++){
			if (A[i] != i + 1){
				return i + 1;
			}
		}
		return A.size() + 1;
	}
};