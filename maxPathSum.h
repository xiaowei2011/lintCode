#include"utils.h"
#include<algorithm>
#include<queue>
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxPathSum1(TreeNode *root) {
		int m = INT_MIN;
		dp(root);
		getMax(root, m);
		return m;
	}
	
	int maxPathSum2(TreeNode *root) {
		int m = INT_MIN;
		dp(root);
		getMax(root, m);
		return m;
	}

	int maxPathSum(TreeNode *root) {
		int m = INT_MIN;
		maxPath(root, m);
		return m;
	}
	int maxPath(TreeNode* root,int &m){
		if (!root)
			return 0;
		int left = maxPath(root->left, m);
		int right = maxPath(root->right, m);
		m = max(m, root->val + max(0, left) + max(0, right));
		return root->val + max(0, max(left, right));
	}
	void getMax(TreeNode *root,int &m){
		if (!root)
			return;
		if (!root->left && !root->right){
			m = max(m, root->val);
		}
		int mv = root->val;
		if (root->left && root->right)
			mv+=min(root->left->val, root->right->val);
		m = max(m, mv);
		getMax(root->left, m);
		getMax(root->right, m);
	}
	int dp(TreeNode *root){
		if (!root)
			return 0;
		int left = dp(root->left);
		int right = dp(root->right);
		root->val += max(left, right);
		return root->val;
	}
	TreeNode* copyTree(const TreeNode* root){
		if (!root)
			return nullptr;
		TreeNode *node = new TreeNode(root->val);
		node->left = copyTree(root->left);
		node->right = copyTree(root->right);
		return node;
	}
	TreeNode* createTree(const vector<int> &vec){
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
	void test(){
		TreeNode n1(1), n2(2), n3(3), n4(4);
		n1.left = &n2;
		n1.right = &n3;
		n3.right = &n4;
		cout << maxPathSum(&n1) << endl;
		cout << Utils::copyTree(&n1) << endl;
		vector<int> vec = { 1, 2, 3, -1, -1, 5 };
		cout << Utils::createTree(vec) << endl;
	}
};