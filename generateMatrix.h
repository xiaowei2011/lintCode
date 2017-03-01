#include"utils.h"
class Solution {
public:
	/**
	* @param n an integer
	* @return a square matrix
	*/
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> vec(n,vector<int>(n));
		int num = 1;
		int circleNum = n / 2;
		if (n % 2 == 1)
			vec[n / 2][n / 2] = n*n;
		for (int i = 0; i < circleNum; i++){
			int last = n - 1 - i;
			for (int j = i; j < last; j++)
				vec[i][j] = num++;
			for (int j = i; j < last; j++)
				vec[j][last] = num++;
			for (int j = last; j > i; j--)
				vec[last][j] = num++;
			for (int j = last; j > i; j--)
				vec[j][i] = num++;
		}
		return vec;
	}
	vector<vector<int>> generateMatrix1(int n) {
		vector<vector<int>> vec(n, vector<int>(n));
		vector<vector<bool>> visited(n, vector<bool>(n));
		int dx[] = { 1, 0, -1, 0 };
		int dy[] = { 0, 1, 0, -1 };
		int i = 0, j = 0, dxy = 0;
		int num = 1;
		while (true){
			if (i == -1 || i == n || j == -1 || j == n || visited[i][j]){
				i -= dy[dxy];
				j -= dx[dxy];
				dxy = (dxy + 1) % 4;
				int ii = i + dy[dxy];
				int jj = j + dx[dxy];
				if (ii == -1 || ii == n || jj == -1 || jj == n || visited[ii][jj])
					return vec;
			}
			else{
				vec[i][j] = num++;
				visited[i][j] = true;
			}
			i += dy[dxy];
			j += dx[dxy];
		}
	}
	void test(){
		Utils::print(generateMatrix1(3));
	}
};