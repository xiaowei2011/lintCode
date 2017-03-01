#include"utils.h"
#include<stack>
class MinStack2 {
private:
	stack<int> stack1;
public:
	MinStack2() {
	
	}

	void push(int number) {
		stack1.push(number);
	}

	int pop() {
		int e = stack1.top();
		stack1.pop();
		return e;
	}
	//要求时间复杂度为O(1),不满足要求
	int min() {
		stack<int> temp = stack1;
		int me = INT_MAX;
		while (!temp.empty()){
			if (me > temp.top()){
				me = temp.top();
			}
			temp.pop();
		}
		return me;
	}
};
//另一种实现方式
class MinStack1 {
public:
	stack<int> stack1;
	int me;

	MinStack1() {
		me = INT_MAX;
	}

	void push(int number) {
		stack1.push(number);
		if (number < me){
			me = number;
		}
	}
	//要求时间复杂度为O(1),不满足要求
	int pop() {
		int e = stack1.top();
		stack1.pop();
		if (e == me){
			me = INT_MAX;
			stack<int> temp = stack1;
			while (!temp.empty()){
				if (me > temp.top()){
					me = temp.top();
				}
				temp.pop();
			}
		}
		return e;
	}

	int min() {
		return me;
	}
};
class MinStack {
private:
	stack<pair<int,int>> stack1;
public:
	MinStack() {

	}

	void push(int number) {
		int me = number;
		if (!stack1.empty() && number>stack1.top().second){
			me = stack1.top().second;
		}
		stack1.push(make_pair(number,me));
	}

	int pop() {
		int e = stack1.top().first;
		stack1.pop();
		return e;
	}
	//要求时间复杂度为O(1),不满足要求
	int min() {
		return stack1.top().second;
	}
};

class Solution{
public:
	void test(){
		MinStack ms;
		ms.push(3);
		ms.push(2);
		ms.push(1);
		cout << ms.min() << endl;
		cout << ms.pop() << endl;
		cout << ms.min() << endl;
		cout << ms.pop() << endl;
		cout << ms.min() << endl;
	}
};
