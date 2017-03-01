#include"utils.h"
#include<queue>
class Solution {
public:
	/**
	* @param root: The root of the binary search tree.
	* @param A and B: two nodes in a Binary.
	* @return: Return the least common ancestor(LCA) of the two nodes.
	*/
	//一简洁算法
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
		if (!root)
			return nullptr;
		if (root == A || root == B)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, A, B);
		TreeNode *right = lowestCommonAncestor(root->right, A, B);
		if (left && right)
			return root;
		else if (left)
			return left;
		else if (right)
			return right;
		else
			return nullptr;
	}
	//此法略绕
	TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *A, TreeNode *B) {
		queue<TreeNode*> queue1;
		vector<TreeNode*> vec;
		queue1.push(root);
		while (!queue1.empty()){
			int len = queue1.size();
			while (len-- > 0){
				TreeNode *p = queue1.front();
				queue1.pop();
				vec.push_back(p);
				if (p->left)
					queue1.push(p->left);
				if (p->right)
					queue1.push(p->right);
			}
		}
		//cout << vec << endl;
		vector<TreeNode*> va,vb;   
		for (int i = vec.size() - 1; i >= 0; i--){
			if (vec[i] == A || vec[i]->left == A || vec[i]->right == A){
				A = vec[i];
				va.push_back(vec[i]);
			}
			if (vec[i] == B || vec[i]->left == B || vec[i]->right == B){
				B = vec[i];
				vb.push_back(vec[i]);
			}
		}
		//cout << va << endl;
		//cout << vb << endl;
		TreeNode *ret=nullptr;
		for (int i =va.size()-1,j=vb.size()-1; i >=0 && j>=0; i--,j--){
			if (va[i] == vb[j])
				ret = va[i];
		}
		return ret;
	}
	
	TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *A, TreeNode *B) {
		TreeNode *pa;
		traverse(root, A, B, pa);
		return pa;
	}

	void traverse(TreeNode *root, TreeNode *A, TreeNode *B,TreeNode *&pa){
		if (root){
			int b1;
			if (isAncestor(root, A) && isAncestor(root, B)){
				pa = root;
			}
			traverse(root->left, A, B, pa);
			traverse(root->right, A, B, pa);
		}
	}

	bool isAncestor(TreeNode *root,TreeNode *node){
		if (root == node)
			return true;
		if (root == nullptr)
			return false;
		return isAncestor(root->left, node) || isAncestor(root->right, node);
	}

	void test(){
		TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
		n1.left = &n2;
		n1.right = &n3;
		n3.left = &n4;
		n3.right = &n5;
		//cout << &n1 << endl;
		//cout << isAncestor(&n4, &n5) << endl;
		cout <<lowestCommonAncestor(&n1, &n4, &n5) << endl;
	}
};