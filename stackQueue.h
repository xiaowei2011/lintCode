#include"utils.h"
#include<stack>
class Queue {
public:
	stack<int> stack1;
	stack<int> stack2;

	Queue() {
		// do intialization if necessary
	}

	void push(int element) {
		stack1.push(element);
	}

	int pop() {
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int e = stack2.top();
		stack2.pop();
		return e;
	}

	int top() {
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int e = stack2.top();
		return e;
	}
};

class Solution{
public:
	void test(){
		Queue queue;
		queue.push(1);
		cout << queue.pop() << endl;
		queue.push(2);
		queue.push(3);
		cout << queue.top() << endl;
		cout << queue.pop() << endl;
	}
};