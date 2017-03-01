#include"utils.h"
#include<stack>
class NestedInteger {
public:

	NestedInteger(){
		this->n = -1;
	}

	NestedInteger(int n){
		this->n = n;
	}

	NestedInteger(vector<NestedInteger> &list){
		n = -1;
		NestedInteger ni;
		for (auto &x : list){
			ni.add(x);
		}
		this->list.push_back(ni);
	}

	void add(NestedInteger &ni){
		if (n!=-1){
			list.push_back(NestedInteger(n));
			n = -1;
		}
		list.push_back(ni);
	}
	// Return true if this NestedInteger holds a single integer,
	// rather than a nested list.
	bool isInteger() const{
		return list.empty();
	}

	// Return the single integer that this NestedInteger holds,
	// if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const{
		return n;
	}

	// Return the nested list that this NestedInteger holds,
	// if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const{
		vector<NestedInteger> *p = new vector<NestedInteger>;
		p->insert(p->end(), list.begin(), list.end());
		return *p;
	}
	friend ostream& operator<<(ostream &out, const NestedInteger &ni){
		if (ni.isInteger()){
			out << ni.n;
		}
		else{
			out << "[";
			for (auto &x : ni.list){
				out <<x<<" ";
			}
			out << "]";
		}
		return out;
	}
private:
	int n;
	vector<NestedInteger> list;
};
class Solution {
public:
	// @param nestedList a list of NestedInteger
	// @return a list of integer
	//递归实现
	vector<int> flatten1(const vector<NestedInteger> &nestedList) {
		vector<int> ret;
		for (auto x : nestedList){
			if (x.isInteger()){
				ret.push_back(x.getInteger());
			}
			else{
				vector<int> temp = flatten1(x.getList());
				ret.insert(ret.end(), temp.begin(), temp.end());
			}
		}
		return ret;
	}

	//非递归实现
	//相当于多叉树
	vector<int> flatten(vector<NestedInteger> &nestedList) {
		vector<int> ret;
		stack<NestedInteger> stack;
		for (int i = 0; i < nestedList.size() && !stack.empty();){
			NestedInteger p;
			if (!stack.empty()){
				p = stack.top();
			}
			else{
				p = nestedList[i++];
			}
			if (p.isInteger()){
				ret.push_back(p.getInteger());
			}
			else{
				const vector<NestedInteger> &temp = p.getList();
				for (int j = 0; j < temp.size(); j++){
					stack.push(temp[j]);
				}
			}
		}
		return ret;
	}

	void test(){
		NestedInteger p1(6);
		NestedInteger p2(4);
		p2.add(p1);
		NestedInteger p3(1);
		p3.add(p2);
		cout << p3 << endl;
	}
};