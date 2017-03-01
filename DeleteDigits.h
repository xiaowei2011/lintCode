#include"utils.h"
#include<string>
class Solution {
public:
	string DeleteDigits(string A, int k) {
		while (k--){
			int id = getDelete(A);
			A.erase(id,1);
		}
		int i;
		for (i = 0; A[i] == '0'; i++);
		A.erase(0, i);
		return A;
	}
	int getDelete(string str){
		int i = 0;
		while (i < str.size() - 1 && str[i] <= str[i + 1])
			i++;
		return i;
	}
	string DeleteDigits1(string A, int k) {
		while (k > 0){
			int id = getMax(A);
			A.erase(id,1);
			k--;
		}
		return A;
	}
	int getMax(string str){
		int max=INT_MIN; 
		int id = -1;
		for (int i = 0; i < str.size(); i++){
			if (max < str[i]){
				max = str[i];
				id = i;
			}
		}
		return id;
	}
	void test(){
		string s = "10009876091";
		cout << DeleteDigits(s,4) << endl;
	}
};
