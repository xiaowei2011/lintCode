#include<iostream>
#include<vector>
#include"utils.h"
using namespace std;
class Solution {
public:
	vector<int> continuousSubarraySum(vector<int>& A) {
		int start = 0, end = A.size() - 1;
		int i = 0, j = 0, sum = 0;
		int max = 0;
		while (i < A.size()){
			sum += A[i];
			if (max < sum){
				max = sum;
				end = i;
				i++;
			}
			else if(sum<0){
				start = i + 1;
				sum = 0;
			}
			i++;
		}
		vector<int> sub;
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	vector<int> continuousSubarraySum2(vector<int>& A) {
		//运行结果不对
		int start = 0, end = A.size() - 1;
		int i = 0, j = 0,sum=0;
		int max = INT_MIN;
		while(j <A.size()){
			sum += A[j];
			if (max < sum){
				max = sum;
				end = j;
			}
			else{
				sum = 0;
			}
			j++;
		}
		sum = 0;
		i = end;
		while (i >= 0){
			sum += A[i];
			if (max < sum){
				max = sum;
				start = i;
			}
			i--;
		}
		vector<int> sub;
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	void test(){
		int a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, -19, 1, 1, 1, 1, 1, 1, 1,
			-2, 1, 1, 1, 1, 1, 1, 1, 1, -2, 1, -15, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		Utils::print(continuousSubarraySum(vec));
	}
	vector<int> continuousSubarraySum1(vector<int>& A) {
		int start = 0, end = 0;
		int max = INT_MIN;
		for (int i = 0; i < A.size(); i++){
			for (int j = i; j < A.size(); j++){
				int sum = getSum(A, i, j);
				if (max < sum){
					max = sum;
					start = i;
					end = j;
				}
			}
		}
		vector<int> sub;
		sub.push_back(start);
		sub.push_back(end);
		return sub;
	}
	int getSum(vector<int>& A, int start, int end){
		int sum = 0;
		for (int i = start; i <= end; i++){
			sum += A[i];
		}
		return sum;
	}
};