#include"utils.h"
class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @return: Void
	*/
	//�Ƚ�����ת�ã�Ȼ�����ҷ�ת��Ϊ�������
	//�ռ临�Ӷ�ΪO(n^2)��û������ԭ�ط�ת
	void rotate1(vector<vector<int>> &matrix) {
		int n = matrix.size();
		vector<vector<int>> temp(n, vector<int>(n));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				temp[i][j] = matrix[j][i];
			}
		}
		int mid = n / 2;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				matrix[i][j] = temp[i][n - 1 - j];
			}
		}
	}
	//�Ľ����£�ʵ��ԭ�ط�ת
	void rotate(vector<vector<int>> &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < i; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n/2; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - 1 - j];
				matrix[i][n - 1 - j] = temp;
			}
		}
	}
	void test(){
		vector<vector<int>> vec = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
		Utils::print(vec);
		rotate(vec);
		Utils::print(vec);
	}
};