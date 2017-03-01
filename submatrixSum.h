#include<iostream>
#include<vector>
#include"utils.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
		vector<vector<int>> ret;
		int row = matrix.size();
		vector<int> point;
		point.push_back(0);
		point.push_back(0);
		ret.push_back(point);
		ret.push_back(point);
		if (row < 1){
			return ret;
		}
		int column = matrix[0].size();
		vector<vector<int>> tempC(row,vector<int>(column));
		vector<vector<int>> tempR(row, vector<int>(column));
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				if (i == 0)
					tempC[i][j] = matrix[i][j];
				else
					tempC[i][j] = tempC[i - 1][j] + matrix[i][j];
				if (j == 0)
					tempR[i][j] = matrix[i][j];
				else
					tempR[i][j] = tempR[i][j-1] + matrix[i][j];
			}
		}
		vector<vector<int>> subSum(row, vector<int>(column));
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				if (i == 0 && j==0)
					subSum[i][j] = matrix[i][j];
				else if (i == 0){
					subSum[i][j] = subSum[i][j - 1] + matrix[i][j];
				}
				else if(j==0){
					subSum[i][j] = subSum[i-1][j] + matrix[i][j];
				}
				else{
					subSum[i][j] = subSum[i - 1][j] + subSum[i][j - 1] - subSum[i - 1][j - 1]
						+matrix[i][j];
				}
			}
		}
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				for (int k = i; k < row; k++){
					for (int m = j; m < column; m++){
						int he = 0;
						if (i == k && j == m)
							he = matrix[i][j];
						else if (i == k)
							he = tempR[i][m] - tempR[i][j] + matrix[i][j];
						else if (j == m)
							he=tempC[k][j]-tempC[i][j]+matrix[i][j];
						else{
							int s1 = 0, s2 = 0, s3 = 0;
							if (i > 0 && j > 0){
								s1 = subSum[i - 1][m];
								s2 = subSum[k][j - 1];
								s3 = subSum[i - 1][j - 1];
							}
							else if (i > 0){
								s1 = subSum[i - 1][m];
								s3 = subSum[i - 1][j];
							}
							else if (j>0){
								s2 = subSum[k][j - 1];
								s3 = subSum[i][j - 1];
							}
							he = subSum[k][m] - s1 - s2 + s3;
						}
						if (he==0){
							ret.clear();
							vector<int> point1, point2;
							point1.push_back(i);
							point1.push_back(j);
							point2.push_back(k);
							point2.push_back(m);
							ret.push_back(point1);
							ret.push_back(point2);
							return ret;
						}
					}
				}
			}
		}
		return ret;
	}
	void test(){
		int a[][3] ={ { 1, 5, 7 }, { 3, 7, -8 }, { 4, -8, 9 } };
		vector<vector<int>> vec;
		vector<int> v1(a[0], a[0] + 3);
		vector<int> v2(a[1], a[1] + 3);
		vector<int> v3(a[2], a[2] + 3);
		vec.push_back(v1);
		vec.push_back(v2);
		vec.push_back(v3);
		Utils::print(vec);
		cout << endl;
		Utils::print(submatrixSum(vec));
	}
};