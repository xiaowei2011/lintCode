#include"utils.h"
#include<string>
class Solution {
public:
	/**
	* @param n The integer
	* @return Roman representation
	*/
	//I=1£¬V=5£¬X=10£¬L=50£¬C=100£¬D=500£¬M=1000
	string intToRoman2(int n) {
		int base[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		string ret;
		int i = 0;
		while (n > 0){
			int count = n / base[i];
			while (count-- > 0){
				ret += symbol[i];
			}
			n %= base[i++];
		}
		return ret;
	}
	//ÁíÒ»ÖÖĞ´·¨
	string intToRoman(int n) {
		int base[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string ret;
		int i = 0;
		while (n > 0){
			if (n >= base[i]){
				ret += symbol[i];
				n -= base[i];
			}
			else{
				i++;
			}
		}
		return ret;
	}

	int romanToInt(string& s) {
		if (s.length() < 1)
			return 0;
		int ret = 0;
		int last = 0;
		for (int i = 0; i < s.length(); i++){
			int base = getBase(s[i]);
			ret += base;
			if (base > last){
				ret -=2*last;
			}
			last = base;
		}
		return ret;
	}
	int getBase(char c){
		switch (c){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return -1;
		}
	}

	void test(){
		cout << intToRoman(105) << endl;
		string s = "IV";
		cout << romanToInt(s) << endl;
	}
};