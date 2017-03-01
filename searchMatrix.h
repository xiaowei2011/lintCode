#include"utils.h"
class Solution {
public:
	
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		int row = matrix.size();
		if (row == 0)
			return false;
		int column = matrix[0].size();
		if (column == 0)
			return false;
		int id=search(matrix, 0, row*column, target);
		if (id == -1)
			return false;
		else
			return true;
	}
	int search(vector<vector<int>> &matrix,int start,int end,int target){
		int row = matrix.size();
		int column = matrix[0].size();
		int low = start, high = end;
		while(low <= high){
			int mid = (low + high) / 2;
			if (matrix[mid / column][mid % column] == target)
				return mid;
			else if (matrix[mid / column][mid % column] < target)
				low=mid+1;
			else
				high=mid-1;
		}
		return -1;
	}
	vector<vector<int>> getVector(int **a, int m, int n){
		vector<vector<int>> vec(m,vector<int>(n));
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				vec[i][j] = *((int*)a+n*i+j);
			}
		}
		return vec;
	}
	void test(){
		int a[][4] = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, {23, 30, 34, 50 }};
		vector<vector<int>> vec = getVector((int**)a, 3, 4);
		Utils::print(vec);
		cout << search(vec,0,12,7) << endl;
	}
};
