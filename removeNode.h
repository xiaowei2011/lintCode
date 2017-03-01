#include"utils.h"
class Solution {
public:
	
	TreeNode* removeNode(TreeNode* root, int value) {
		//Ò»¼ò½àËã·¨
		if (!root)
			return root;
		TreeNode *cur = root, *pa = nullptr;
		while (cur && cur->val != value){
			pa = cur;
			if (cur->val > value)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (!cur)
			return root;
		if (cur->left && cur->right){
			TreeNode *son = cur->left, *sp = cur;
			while (son->right){
				sp = cur;
				son = son->right;
			}
			cur->val = son->val;
			cur = son;
			pa = sp;
		}
		TreeNode *base;
		if (cur->right)
			base = cur->right;
		else
			base = cur->left;
		if (cur == root)
			root = base;
		else
			if (pa->left == cur)
				pa->left = base;
			else
				pa->right = base;
		delete cur;
		return root;
	}
	TreeNode* removeNode1(TreeNode* root, int value) {
		if (!root)
			return nullptr;
		TreeNode *p = root;
		if (p->val < value)
			p->right = removeNode1(p->right, value);
		else if (p->val > value)
			p->left = removeNode1(p->left, value);
		else if (p->left && p->right){
			TreeNode *min = getMin(p->right);
			TreeNode *temp = removeNode1(p->right, min->val);
			min->left = p->left;
			min->right = temp;
			if (p == root){
				return min;
			}
			TreeNode *pa = nullptr;
			bool left = false;
			getParent(root, p, pa, left);
			if (left)
				pa->left = min;
			else
				pa->right = min;
		}
		else if (!p->left && !p->right){
			if (p == root)
				return nullptr;
			TreeNode *pa = nullptr;
			bool left = false;
			getParent(root, p, pa, left);
			if (left)
				pa->left = nullptr;
			else
				pa->right = nullptr;
		}
		else{
			TreeNode *temp = p->left ? p->left : p->right;
			if (p == root)
				return temp;
			TreeNode *pa = nullptr;
			bool left = false;
			getParent(root, p, pa, left);
			if (left)
				pa->left = temp;
			else
				pa->right = temp;
		}
		return root;
	}
	void getParent(TreeNode *root, TreeNode *p, TreeNode *&pa, bool &left){
		if (root){
			if (root->left == p){
				pa = root;
				left = true;
			}
			else if (root->right == p){
				pa = root;
				left = false;
			}
		}
	}
	TreeNode *getMin(TreeNode *root){
		while (root->left){
			root = root->left;
		}
		return root;
	}
};