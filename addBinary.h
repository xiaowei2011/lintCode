#include<string>
#include"utils.h"
class Solution {
public:
	/**
	* @param a a number
	* @param b a number
	* @return the result
	*/
	//直接以字符串的形式相加
	string addBinary(string& a, string& b) {
		string sum = "";
		int over = 0;
		for (int i = 1; i<=a.size() || i<=b.size(); i++){
			int c1 = a.size() - i >= 0 && a.size() - i < a.size() ? a[a.size() - i] - '0' : 0;
			int c2 = b.size() - i >= 0 && b.size() - i < b.size() ? b[b.size() - i] - '0' : 0;
			int c = c1 + c2 + over;
			over = c > 1 ? 1 : 0;
			char ch = c == 1 || c==3 ? '1' : '0';
			sum = ch + sum;
		}
		if (over == 1){
			sum = '1' + sum;
		}
		return sum;
	}

	string addBinary1(string& a, string& b) {
		string sum = "";
		int ai = convert(a);
		int bi = convert(b);
		int s = ai + bi;
		if (s == 0)
			return "0";
		while (s > 0){
			string temp = ((s & 1) == 1) ? "1" : "0";
			sum = temp + sum;
			s = s >> 1;
		}
		return sum;
	}
	int convert(string& a){
		int ai = 0;
		for (int i = 0; i < a.length(); i++){
			int x = a[i] == '0' ? 0 : 1;
			ai = ai * 2 + x;
		}
		return ai;
	}
	void test(){
		string a = "11",b="1";
		cout << addBinary(a, b) << endl;
	}
};