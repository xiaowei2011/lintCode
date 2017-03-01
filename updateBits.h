#include"utils.h"
#include<iomanip>
class Solution {
public:
	
	int updateBits(int n, int m, int i, int j) {
		m <<= i;
		int bit = 1;
		bit <<= i;
		int count = j - i + 1;
		while (count > 0){
			n &= ~bit;
			bit <<= 1;
			count--;
		}
		return n | m;
	}
	int updateBits1(int n, int m, int i, int j) {
		//运行不通过
		int left = 0xffffffff;
		cout << hex <<n<< endl;
		left <<= (j+1);
		left &= n;
		cout << left << endl;
		unsigned int right = 0xffffffff;
		right >>= (32 - i);
		cout << right << endl;
		right &= n;
		int mid = m;
		mid <<= i;
		//cout << mid << endl;
		int ret = left | right | mid;
		return ret;
	}
	void test(){
		//cout << updateBits(-521, 0, 31, 31) << endl;
		cout << updateBits(-521, 0, 31, 31)<<endl;
	}
};