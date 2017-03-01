#include"utils.h"
#include<stack>
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		//∑«µ›πÈ µœ÷
		vector<int> vec;
		stack<TreeNode*> stack;
		TreeNode *p = root;
		while (p || !stack.empty()){
			while (p){
				stack.push(p);
				p = p->left;
			}
			if (!stack.empty()){
				p = stack.top();
				vec.push_back(p->val);
				stack.pop();
				p = p->right;
			}
		}
		return vec;
	}
	vector<int> preorderTraversal1(TreeNode *root) {
		vector<int> vec;
		traverse(root, vec);
		return vec;
	}
	void traverse(TreeNode *root,vector<int> &vec){
		if (root){
			vec.push_back(root->val);
			traverse(root->left,vec);
			traverse(root->right,vec);
		}
	}
};