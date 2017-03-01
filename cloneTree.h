#include"utils.h"
class Solution {
public:
	/**
	* @param root: The root of binary tree
	* @return root of new tree
	*/
	TreeNode* cloneTree(TreeNode *root) {
		if (!root){
			return nullptr;
		}
		TreeNode *node = new TreeNode(root->val);
		node->left = cloneTree(root->left);
		node->right = cloneTree(root->right);
		return node;
	}

	//一很原始的方法
	TreeNode* cloneTree1(TreeNode *root) {
		if (!root)
			return nullptr;
		vector<TreeNode*> vec;
		int id = 0;
		map<TreeNode*, int> src;
		createNode(root, src, id, vec);
		createLink(root, src, vec);
		return vec[0];
	}
	//创建节点
	void createNode(TreeNode*root, map<TreeNode*,int> &src,int &id, vector<TreeNode*> &vec){
		if (root){
			vec.push_back(new TreeNode(root->val));
			src[root] = id++;
			createNode(root->left,src,id,vec);
			createNode(root->right,src,id,vec);
		}
	}
	//创建联系
	void createLink(TreeNode*root, map<TreeNode*, int> &src, vector<TreeNode*> &vec){
		if (root){
			if (root->left)
				vec[src[root]]->left = vec[src[root->left]];
			if (root->right)
				vec[src[root]]->right = vec[src[root->right]];
			createLink(root->left,src,vec);
			createLink(root->right,src,vec);
		}
	}
	void test(){
		TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
		n1.left = &n2;
		n1.right = &n3;
		n2.left = &n4;
		n2.right = &n5;
		cout << cloneTree1(&n1) << endl;
	}
};