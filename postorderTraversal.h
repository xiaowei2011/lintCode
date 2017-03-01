#include"utils.h"
#include<stack>
class Solution {
	/**
	* @param root: The root of binary tree.
	* @return: Postorder in vector which contains node values.
	*/
public:
	//非递归实现
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ret;
		stack<pair<TreeNode*,int>> stack;
		TreeNode *p = root;
		while (p || !stack.empty()){
			while (p){
				stack.push(make_pair(p,1));
				p = p->left;
			}
			if (stack.top().second == 1){
				p = stack.top().first;
				stack.top().second = 2;
				p = p->right;
			}
			else{
				p = stack.top().first;
				stack.pop();
				ret.push_back(p->val);
				p = nullptr;//将p置为空，跳过向左走，直接向右走
			}
		}
		return ret;
	}

	//递归法
	vector<int> postorderTraversal1(TreeNode *root) {
		vector<int> ret;
		traverse(root, ret);
		return ret;
	}
	void traverse(TreeNode *root,vector<int> &vec){
		if (root){
			traverse(root->left,vec);
			traverse(root->right, vec);
			vec.push_back(root->val);
		}
	}
	void test(){
		TreeNode n1(1),n2(2),n3(3);
		n1.right = &n2;
		n2.left = &n3;
		Utils::print(postorderTraversal(&n1));
	}
};