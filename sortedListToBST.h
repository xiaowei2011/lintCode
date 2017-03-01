#include"utils.h"
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (!head)
			return nullptr;
		int len = 0;
		ListNode *p = head;
		while (p){
			len++;
			p = p ->next;
		}
		if (len == 1){
			return new TreeNode(head->val);
		}
		else if (len == 2){
			TreeNode *root = new TreeNode(head->val);
			root->right = new TreeNode(head->next->val);
			return root;
		}
		len /= 2;
		p = head;
		ListNode *pre = nullptr;
		int count = 0;
		while (count < len){
			count++;
			pre = p;
			p = p->next;
		}
		pre->next = nullptr;
		TreeNode *root = new TreeNode(p->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(p->next);
		return root;
	}
	TreeNode *sortedListToBST1(ListNode *head) {
		//‘À––≥¨ ±
		vector<ListNode*> vec;
		while (head){
			vec.push_back(head);
			head = head->next;
		}
		TreeNode *root = addTreeNode(vec, 0, vec.size() - 1);
		return root;
	}
	TreeNode *addTreeNode(vector<ListNode*> array, int left, int right){
		int l = left, r = right;
		TreeNode *root = nullptr;
		if (left <= right){
			int mid = (left + right) / 2;
			root = new TreeNode(array[mid]->val);
			root->left = addTreeNode(array, left, mid - 1);
			root->right = addTreeNode(array, mid + 1, right);
		}
		return root;
	}
	void test(){
		int a[] = { -1,0,2 };
		ListNode *h = Utils::arrayToList(a,sizeof(a)/sizeof(int));
		TreeNode *root = sortedListToBST(h);
		cout << root << endl;
	}
};