#include"utils.h"
#include<algorithm>
class Solution {
public:
	int id=0;
	TreeNode *sortedArrayToBST(vector<int> &A) {
		TreeNode *root = addTreeNode(A, 0, A.size()-1);
		return root;
	}
	TreeNode *addTreeNode(vector<int> array,int left,int right){
		int l = left, r = right;
		TreeNode *root = nullptr;
		if (left <= right){
			int mid = (left + right) / 2;
			root = new TreeNode(array[mid]);
			root->left = addTreeNode(array, left, mid - 1);
			root->right = addTreeNode(array, mid+1, right);
		}
		return root;
	}
	TreeNode *sortedArrayToBST1(vector<int> &A) {
		//‘À––≥¨ ±
		if (A.size() < 1)
			return nullptr;
		int len = A.size();
		vector<TreeNode*> vec(len);
		int k = 0;
		for (auto &x: vec){
			x = new TreeNode(-1);
		}
		for (int i = 0; i < len; i++){
			if (2 * i + 1 < len)
				vec[i]->left = vec[2 * i + 1];
			if (2 * i + 2 < len)
				vec[i]->right = vec[2 * i + 2];
		}
		traverse(vec[0],A);
		return vec[0];
	}
	void traverse(TreeNode *root,vector<int> vec){
		if (root != nullptr){
			traverse(root->left,vec);
			root->val=vec[id++];
			traverse(root->right,vec);
		}
	}
	void test(){
		int a[] = {1,2,3,4};
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		TreeNode *root = sortedArrayToBST(vec);
		cout << root << endl;
	}
};