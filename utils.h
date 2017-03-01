#ifndef UTILS_H_
#define UTILS_H_
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include"bean.h"
using namespace std;
class Utils{
public:
	template<typename Type>
	static void print(const vector<Type> &vec);
	template<typename Type>
	static void print(const Type a[], int len);
	template<typename Type>
	static void print(const vector<vector<Type>> &vec);
	template<typename Type1, typename Type2>
	static void print(const pair<Type1, Type2> a[], int len);
	template<typename Type1, typename Type2>
	static void print(const vector<pair<Type1, Type2>> vec);
	template<typename Type1, typename Type2>
	static void print(map<Type1, Type2> &m);
	template<typename Type1, typename Type2>
	static void print(const unordered_map<Type1, Type2> &m);
	template<typename Type1, typename Type2>
	static void print(const unordered_map<Type1, vector<Type2>> &m);
	template<typename Type>
	static vector<vector<Type>> toVector(Type a[][],int m,int n);
	template<typename Type>
	static void print(const set<Type> &s);
	//数组转化为链表
	static ListNode* arrayToList(int a[],int len);
	static ListNode* arrayToList(vector<int> vec);
	//使用数组创建二叉树
	static TreeNode* createTree(const vector<int> &vec);
	static TreeNode* copyTree(const TreeNode* root);
};
TreeNode* Utils::copyTree(const TreeNode* root){
	if (!root)
		return nullptr;
	TreeNode *node = new TreeNode(root->val);
	node->left = copyTree(root->left);
	node->right = copyTree(root->right);
	return node;
}
TreeNode* Utils::createTree(const vector<int> &vec){
	if (vec.size() < 1)
		return nullptr;
	queue<TreeNode**> q;
	TreeNode *root = new TreeNode(vec[0]);
	q.push(&root->left);
	q.push(&root->right);
	for (int i = 1; i < vec.size() && !q.empty(); i++){
		TreeNode **p = q.front();
		q.pop();
		if (vec[i] != -1){
			*p = new TreeNode(vec[i]);
			q.push(&(*p)->left);
			q.push(&(*p)->right);
		}
	}
	return root;
}

template<typename Type>
void Utils::print(const set<Type> &s){
	cout << "[";
	for (set<Type>::iterator it = s.begin(); it != s.end(); it++){
		cout << *it << " ";
	}
	cout <<"]"<<endl;
}
ListNode* Utils::arrayToList(vector<int> vec){
	vector<ListNode*> ret;
	for (int i = 0; i < vec.size(); i++){
		ret.push_back(new ListNode(vec[i]));
	}
	for (int i = 0; i < vec.size() - 1; i++){
		ret[i]->next = ret[i + 1];
	}
	if (ret.size() == 0)
		return NULL;
	return ret[0];
}
ListNode* Utils::arrayToList(int a[], int len){
	vector<ListNode*> vec;
	for (int i=0; i< len; i++){
		vec.push_back(new ListNode(a[i]));
	}
	for (int i = 0; i < vec.size()-1; i++){
		vec[i]->next = vec[i + 1];
	}
	if (vec.size() == 0)
		return NULL;
	return vec[0];
}

template<typename Type>
vector<vector<Type>> Utils::toVector(Type a[][], int m, int n){
	vector<vector<Type>> vec(m, vector<Type>(n));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			vec[i][j] = a[i][j];
		}
	}
	return vec;
}
template<typename Type1, typename Type2>
void Utils::print(const unordered_map<Type1, vector<Type2>> &m){
	cout << "[";
	for (unordered_map<Type1, vector<Type2>>::const_iterator it = m.begin(); it != m.end(); it++){
		cout << "(" << it->first << ",[";
		for (vector<Type2>::const_iterator ite = it->second.begin(); ite != it->second.end(); ite++){
			cout << *ite;
			if (ite != --it->second.end()) cout << " ";
		}
		cout << "]) ";
	}
	cout << "]" << endl;
}
template<typename Type1, typename Type2>
void Utils::print(map<Type1, Type2> &m){
	cout << "[";
	for (map<Type1, Type2>::iterator it = m.begin(); it != m.end(); it++){
		cout << "(" << it->first << "," << it->second << ") ";
	}
	cout << "]" << endl;
}
template<typename Type1, typename Type2>
void Utils::print(const unordered_map<Type1, Type2> &m){
	cout << "[";
	for (unordered_map<Type1, Type2>::const_iterator it = m.begin(); it != m.end(); it++){
		cout << "(" << it->first << "," << it->second << ") ";
	}
	cout << "]" << endl;
}
template<typename Type1, typename Type2>
void Utils::print(const vector<pair<Type1, Type2>> vec){
	cout << "[";
	for (int i = 0; i < vec.size(); i++){
		cout << "(" << vec[i].first << "," << vec[i].second << ") ";
	}
	cout << "]" << endl;
}

template<typename Type1, typename Type2>
void Utils::print(const pair<Type1, Type2> a[], int len){
	cout << "[";
	for (int i = 0; i < len; i++){
		cout << "("<<a[i].first << ","<<a[i].second<<") ";
	}
	cout << "]" << endl;
}

template<typename Type>
void Utils::print(const Type a[], int len){
	cout << "[";
	for (int i = 0; i < len; i++){

		cout << a[i] << " ";
	}
	cout << "]" << endl;
}
template<typename Type>
void Utils::print(const vector<Type> &vec){
	cout << "[";
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}
template<typename Type>
void Utils::print(const vector<vector<Type>> &vec){
	for (int i = 0; i < vec.size(); i++){
		cout << "[";
		for (int j = 0; j < vec[i].size(); j++){
			cout << vec[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

#endif /* UTILS_H_ */
