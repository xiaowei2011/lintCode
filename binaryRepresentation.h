#include"Utils.h"
#include<string>
#include<sstream>
class Solution {
public:
	string binaryRepresentation(string n) {
		stringstream ns(n);
		double num;
		ns >> num;
		cout << num+1.3 << endl;
		return "";
	}
	string binaryRepresentation1(string n) {
		int len = n.length();
		int id = n.find('.');
		string left;
		string right;
		if (id == -1){
			left = n;
		}
		else{
			left = n.substr(0, id);
			right = '0' + n.substr(id);
		}
		stringstream ls(left), rs(right);
		int ln;
		double rn;
		ls >> ln;
		rs >> rn;
		int count = 32;
		string rl, rr;
		while (ln != 0){
			rl = (ln & 1 == 1 ? "1" : "0") + rl;
			ln >>= 1;
		}
		while (rn != 0 && count > 0){
			rr += rn * 2 >= 1 ? "1" : "0";
			rn *= 2;
			rn -= rn >= 1 ? 1 : 0;
			count--;
		}
		if (rl == "")
			rl = "0";
		stringstream rt(rr);
		int rtn;
		rt >> rtn;
		if (rtn == 0){
			rr = "";
		}
		else{
			rr = '.' + rr;
		}
		if (rn != 0)
			return "ERROR";
		else
			return rl + rr;
	}
	void test(){
		string s = "123.2";
		cout << binaryRepresentation(s) << endl;
	}
};