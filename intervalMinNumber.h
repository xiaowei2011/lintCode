#include"utils.h"
class SegmentTreeNode {
public:
	int start, end, min;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int min) {
		this->start = start;
		this->end = end;
		this->min = min;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/**
	*@param A, queries: Given an integer array and an query list
	*@return: The result list
	*/
	vector<int> intervalMinNumber1(vector<int> &A, vector<Interval> &queries) {
		//时间复杂度达到了O(logN)，运行仍然超时，郁闷
		vector<int> vec;
		for (int i = 0; i < queries.size(); i++){
			vec.push_back(findMin(A, queries[i].start, queries[i].end));
		}
		return vec;
	}

	vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
		vector<int> vec;
		SegmentTreeNode *root = build(A, 0, A.size() - 1);
		for (auto &in : queries){
			vec.push_back(query(root, in.start, in.end));
		}
		return vec;
	}
	SegmentTreeNode * build(vector<int>& A, int start, int end) {
		if (start == end)
			return new SegmentTreeNode(start, end, A[start]);
		int mid = (start + end) / 2;
		SegmentTreeNode *node = new SegmentTreeNode(start, end, 0);
		node->left = build(A, start, mid);
		node->right = build(A, mid + 1, end);
		node->min = min(node->left->min, node->right->min);
		return node;
	}
	int query(SegmentTreeNode *root, int start, int end) {
		if (start == root->start && end == root->end)
			return root->min;
		int mid = (root->start + root->end) / 2;
		if (end <= mid)
			return query(root->left, start, end);
		else if (start > mid)
			return query(root->right, start, end);
		else
			return min(query(root->left, start, mid), query(root->right, mid + 1, end));
	}
	int findMin(vector<int> &A, int start, int end){
		if (start == end)
			return A[start];
		int mid = start + (end - start) / 2;
		return min(findMin(A, start, mid), findMin(A, mid + 1, end));
	}
	void test(){
		map<int, int> m = { { 1, 2 }, { 2, 3 }, { 5, 7 }, { 4, 5 } };
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
			cout << it->first << "=" << it->second << endl;
		}
	}
};