#include"utils.h"
#include<string>
#include<algorithm>
class Solution {
public:
	/**
	* @param s : A string
	* @return : A string
	*/
	//简洁一点的写法
	string reverseWords2(string s) {
		if (s == "")
			return s;
		vector<string> vec;
		for (int i = 0; i < s.size(); i++){
			while (i < s.size() && s[i] == ' ')
				i++;
			int a = i;
			while (i < s.size() && s[i] != ' ')
				i++;
			int b = i;
			if (i == s.size() - 1){
				vec.push_back(s.substr(a, s.size() - a));
				break;
			}
			vec.push_back(s.substr(a, b - a));
		}
		string ret;
		for (auto &x : vec){
			ret = x + ' ' + ret;
		}
		//去除首尾空格
		int left = 0,right=ret.size()-1;
		while (ret[left] == ' ')
			left++;
		while (ret[right] == ' ')
			right--;
		return ret.substr(left,right-left+1);
	}
	//这方法太麻烦，不好
	string reverseWords1(string s) {
		vector<string> vec;
		int index=0;
		int count = 0;
		while (index<s.size() && s[index] == ' '){
			index++;
			count++;
		}
		s.erase(0, count);
		index = s.size() - 1;
		count = 0;
		while (index < s.size() && s[index] == ' '){
			index--;
			count++;
		}
		s.erase(index+1,count);
		s = s + ' ';
		int pre = 0;
		for (int i = pre+1; i < s.size(); i++){
			if (s[i] == ' '){
				vec.push_back(s.substr(pre,i-pre));
				while (i<s.size() && s[i] == ' ')
					i++;
				pre = i;
			}
		}
		string ret;
		for (auto &x : vec){
			ret = x+' ' + ret;
		}
		if (ret[ret.size() - 1] == ' ')
			ret.erase(ret.size() - 1, 1);
		return ret;
	}
	void test(){
		string s = "the sky is blue   ";
		cout <<"-->"<<reverseWords2(s)<<"<--" << endl;
		//cout << (s[3] == ' ') << endl;
	}
};