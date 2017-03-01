#include"utils.h"
class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @return: Void
	*/
	//时间复杂度为O(m+n),不满足要求
	void setZeroes1(vector<vector<int>> &matrix) {
		if (matrix.size() < 1 || matrix[0].size() < 1)
			return;
		vector<bool> row(matrix.size()),column(matrix[0].size());
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				if (matrix[i][j] == 0)
					row[i] = column[j] = true;
			}
		}
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				if (row[i] || column[j])
					matrix[i][j] = 0;
			}
		}
	}
	//一神奇算法
	void setZeroes(vector<vector<int>> &matrix) {
		int m = matrix.size();
		if (m < 1)
			return;
		int n = matrix[0].size();
		bool row=false, column=false;
		for (auto &x : matrix[0])
			if (x == 0){
				row = true;
				break;
			}
		for (auto &x : matrix)
			if (x[0] == 0){
				column = true;
				break;
			}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		for (int i = 1; i < n; i++)
			if (matrix[0][i] == 0)
				for (auto &x : matrix)
					x[i] = 0;
		for (int i = 1; i < m; i++)
			if (matrix[i][0] == 0)
				for (auto &x : matrix[i])
					x = 0;
		if (row)
			for (auto &x : matrix[0])
				x = 0;
		if (column)
			for (auto &x : matrix)
				x[0] = 0;
	}
	void test(){
		vector<vector<int>> vec = { { -4, 0 }, { -8, 0 }, { 8,-10 } };
		setZeroes(vec);
		Utils::print(vec);
	}
};