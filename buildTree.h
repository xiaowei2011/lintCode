#include"utils.h"
class Solution {
	
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return build(preorder,inorder);
	}
	TreeNode *build(vector<int> &preorder, vector<int> &inorder){
		if (preorder.size() < 1)
			return nullptr;
		if (preorder.size() == 1){
			return new TreeNode(preorder.front());
		}
		TreeNode *p = new TreeNode(preorder.front());
		int n=find(inorder.begin(), inorder.end(), preorder.front()) - inorder.begin();
		vector<int> prel(preorder.begin() + 1, preorder.begin() + 1+n);
		vector<int> prer(preorder.begin() + 1 + n, preorder.end());
		vector<int> inl(inorder.begin(), inorder.begin() + n);
		vector<int> inr(inorder.begin() + n+1, inorder.end());
		p->left = build(prel, inl);
		p->right = build(prer, inr);
		return p;
	}
	void createTree(const vector<int> &vec,TreeNode *&root,int n){
		if (n >= vec.size() || vec[n] == -1){
			root = nullptr;
			return;
		}
		root = new TreeNode(vec[n]);
		createTree(vec, root->left, 2 * n + 1);
		createTree(vec, root->right, 2 * n + 2);
	}
	void test(){
		int a[] = { 2,4,1,3 };
		int b[] = { 1,2,4,3 };
		vector<int> va(a, a + sizeof(a) / sizeof(int));
		vector<int> vb(b, b + sizeof(b) / sizeof(int));
		TreeNode *root=buildTree(va,vb);
		cout << root << endl;
	}
};