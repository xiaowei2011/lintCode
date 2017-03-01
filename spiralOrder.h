#include"utils.h"
#include<algorithm>
class Solution {
public:
	/**
	* @param matrix a matrix of m x n elements
	* @return an integer array
	*/
	//运行不通过，
	vector<int> spiralOrder1(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return vector<int>();
		int n = matrix[0].size();
		int len = m*n;
		int up = 0, down = 0, left = 0, right = 0;
		int order = 0;
		vector<int> vec;
		while (len > 0){
			switch (order){
			case 0:
				for (int i = left; i < n - right && len > 0; i++){
					vec.push_back(matrix[up][i]);
					len--;
				}
				up++;
				order = 1;
				break;
			case 1:
				for (int i = up; i < m - down && len > 0; i++){
					vec.push_back(matrix[i][n - 1 - right]);
					len--;
				}
				right++;
				order = 2;
				break;
			case 2:
				for (int i = n - 1 - right; i >= left && len > 0; i--){
					vec.push_back(matrix[n - 1 - down][i]);
					len--;
				}
				down++;
				order = 3;
				break;
			default:
				for (int i = m - 1 - down; i >= up && len > 0; i--){
					vec.push_back(matrix[i][left]);
					len--;
				}
				left++;
				order = 0;
			}
		}
		return vec;
	}
	//每次删除一行或一列
	vector<int> spiralOrder2(vector<vector<int>>& matrix) {
		int order = 0;
		vector<int> vec;
		while (matrix.size() > 0 && matrix.front().size() > 0){
			switch (order){
			case 0:
				vec.insert(vec.end(), matrix.front().begin(), matrix.front().end());
				matrix.erase(matrix.begin());
				order = (order + 1) % 4;
				break;
			case 1:
				for (int i = 0; i < matrix.size(); i++){
					vec.push_back(matrix[i].back());
					matrix[i].erase(matrix[i].end() - 1);
				}
				order = (order + 1) % 4;
				break;
			case 2:
				vec.insert(vec.end(), matrix.back().rbegin(), matrix.back().rend());
				matrix.erase(matrix.end() - 1);
				order = (order + 1) % 4;
				break;
			default:
				for (int i = matrix.size() - 1; i >= 0; i--){
					vec.push_back(matrix[i].front());
					matrix[i].erase(matrix[i].begin());
				}
				order = (order + 1) % 4;
			}
		}
		return vec;
	}
	vector<int> spiralOrder3(vector<vector<int>>& matrix) {
		vector<int> vec;
		int m = matrix.size();
		if (m == 0)
			return vec;
		int n = matrix[0].size();
		int circleNum = (min(m, n) + 1) / 2;
		for (int i = 0; i < circleNum; i++){
			int lastRow = m - 1 - i;
			int lastCol = n - 1 - i;
			if (i == lastRow){
				for (int j = i; j <= lastCol; j++){
					vec.push_back(matrix[i][j]);
				}
			}
			else if (i == lastCol){
				for (int j = i; j <= lastRow; j++){
					vec.push_back(matrix[j][i]);
				}
			}
			else{
				for (int j = i; j < lastCol; j++){
					vec.push_back(matrix[i][j]);
				}
				for (int j = i; j < lastRow; j++){
					vec.push_back(matrix[j][lastCol]);
				}
				for (int j = lastCol; j > i; j--){
					vec.push_back(matrix[lastRow][j]);
				}
				for (int j = lastRow; j > i; j--){
					vec.push_back(matrix[j][i]);
				}
			}
		}
		return vec;
	}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		//一神奇算法,算法很简洁，但需要O(m*n)的空间复杂度
		vector<int> vec;
		int m = matrix.size();
		if (m == 0)
			return vec;
		int n = matrix[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		int dx[] = { 1, 0, -1, 0 };
		int dy[] = { 0, 1, 0, -1 };
		int i = 0, j = 0, dxy = 0;
		while (true){
			if (i == -1 || i == m || j == -1 || j == n || visited[i][j]){
				i -= dy[dxy];
				j -= dx[dxy];
				dxy = (dxy + 1) % 4;
				int ii = i + dy[dxy];
				int jj = j + dx[dxy];
				if (ii == -1 || ii == m || jj == -1 || jj == n || visited[i + dy[dxy]][j + dx[dxy]])
					return vec;
			}
			else{
				vec.push_back(matrix[i][j]);
				visited[i][j] = true;
			}
			i += dy[dxy];
			j += dx[dxy];
		}
	}
	void test(){
		vector<vector<int>> vec = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
		vec = { { 10 } };
		Utils::print(vec);
		Utils::print(spiralOrder(vec));
		cout << (-1 % 2) << endl;
	}
};