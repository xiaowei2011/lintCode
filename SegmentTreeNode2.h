#include"utils.h"
#include<algorithm>
class SegmentTreeNode {
public:
	int start, end, max;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int max) {
		this->start = start;
		this->end = end;
		this->max = max;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	*@param A: a list of integer
	*@return: The root of Segment Tree
	*/
	SegmentTreeNode * build(vector<int>& A) {
		if (A.size() < 1)
			return nullptr;
		build(A, 0, A.size() - 1);
	}
	//每构建一个节点都得计算一次最大值，时间复杂度略高
	SegmentTreeNode * build1(vector<int>& A,int start,int end) {
		if (start == end)
			return new SegmentTreeNode(start, end, A[start]);
		int mid = (start + end) / 2;
		SegmentTreeNode *node = new SegmentTreeNode(start,end,*max_element(A.begin()+start,
			A.begin()+end+1));
		node->left = build1(A, start, mid);
		node->right = build1(A, mid + 1, end);
		return node;
	}
	//改进如下
	SegmentTreeNode * build(vector<int>& A, int start, int end) {
		if (start == end)
			return new SegmentTreeNode(start, end, A[start]);
		int mid = (start + end) / 2;
		SegmentTreeNode *node = new SegmentTreeNode(start, end, 0);
		node->left = build(A, start, mid);
		node->right = build(A, mid + 1, end);
		node->max = max(node->left->max, node->right->max);
		return node;
	}
	int query(SegmentTreeNode *root, int start, int end) {
		if (start==root->start && end==root->end)
			return root->max;
		int mid = (root->start + root->end) / 2;
		if (end <= mid)
			return query(root->left, start, end);
		else if (start > mid)
			return query(root->right, start, end);
		else
			return max(query(root->left, start, mid), query(root->right, mid + 1, end));
	}

	void modify(SegmentTreeNode *root, int index, int value) {
		if (root->start == index && root->end == index){
			root->max = value;
			return;
		}
		int mid = (root->start + root->end) / 2;
		if (index <= mid)
			modify(root->left, index, value);
		else     
			modify(root->right, index, value);
		root->max = max(root->left->max, root->right->max);
	}
	
};