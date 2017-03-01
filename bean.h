#ifndef BEAN_H_
#define BEAN_H_
#include<iostream>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	friend ostream& operator<<(ostream &out, TreeNode* node);
	friend ostream& operator<<(ostream &out, const vector<TreeNode*> &vec);
};
ostream& operator<<(ostream &out, TreeNode* node){
	if (node == NULL){
		cout << "#";
		return out;
	}
	out << "[ " << node->val << " " << node->left << " " << node->right << " ]";
	return out;
}
class Interval{
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
	friend ostream& operator<<(ostream &out, const Interval &interval);
};
ostream& operator<<(ostream &out, const Interval &interval){
	out << "[" << interval.start << "," << interval.end << "]";
	return out;
}
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
	friend ostream& operator<<(ostream &out, ListNode* node);
};
ostream& operator<<(ostream &out, ListNode* node){
	if (node == NULL){
		out << "N";
		return out;
	}
	out << node->val << "->" << node->next;
	return out;
}
struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	friend ostream& operator<<(ostream &out, RandomListNode* node);
};
ostream& operator<<(ostream &out, RandomListNode* node){
	if (node == nullptr){
		out << "N";
		return out;
	}
	out << node->label << "(->" << node->random << ") " << "->" << node->next;
	return out;
}
ostream& operator<<(ostream &out, const vector<TreeNode*> &vec){
	out << "[";
	for (auto x : vec){
		out << " " << x->val;
	}
	out << "]" << endl;
	return out;
}
#endif