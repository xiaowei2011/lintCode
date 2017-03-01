#ifndef TEST_H_
#define TEST_H_
#include"utils.h"
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
class Solution{
public:
	
	void test(){
		test3();
	}

	void test3(){
		cout << (1 == 2 == 0) << endl;
	}

	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	void test2(){
		string s1 = "aa",s2="aa";
		cout << &s1 << endl;
		cout << &s2 << endl;
		cout << (&s1 == &s2) << endl;
		int *elem = new int[10]();
		for (int i = 0; i < 10;i++)
		{
			cout << *elem++;
		}
	}
	void test1(){
		int x, y, z;
		cin >> x >> y >> z;
		x > y ? cout << 1 << endl : cout<<2<<endl;
		cout << x << y << z << endl;
	}
};


#endif /* TEST_H_ */
