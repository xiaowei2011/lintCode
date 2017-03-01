#ifndef LICS_H_
#define LICS_H_
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int longestIncreasingContinuousSubsequence(vector<int>& A) {
		if (A.size()<1){
			return 0;
		}
		int max1 = 1;
		for (int i = 0; i < A.size(); i++){
			int len = 1;
			int pre = A[i];
			for (int j = i+1; j < A.size(); j++){
				if (pre < A[j]){
					len++;
					pre = A[j];
				}else{
					break;
				}
			}
			if (len > max1){
				max1 = len;
			}
		}
		int max2 = 1;
		for (int i = 0; i < A.size(); i++){
			int len = 1;
			int pre = A[i];
			for (int j = i + 1; j < A.size(); j++){
				if (pre > A[j]){
					len++;
					pre = A[j];
				}else{
					break;
				}
			}
			if (len > max2){
				max2 = len;
			}
		}
		return max1 > max2 ? max1 : max2;
	}
};
#endif