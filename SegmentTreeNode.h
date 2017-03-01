#include"utils.h"
class SegmentTreeNode {
public:
	int start, end, count;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int count) {
		this->start = start;
		this->end = end;
		this->count;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	*@param root, start, end: The root of segment tree and
	*                         an segment / interval
	*@return: The count number in the interval n(start, end),
	*/
	int query(SegmentTreeNode *root, int start, int end) {
		if (!root || start>end)
			return 0;
		if (start <= root->start && end >= root->end)
			return root->count;
		int mid = (root->start + root->end) / 2;
		if (end <= mid)
			return query(root->left, start, end);
		else if (start > mid)
			return query(root->right, start, end);
		else
			return query(root->left, start, mid)+query(root->right, mid + 1, end);
	}
	
	void test(){
		//
	}
};