#include"utils.h"
#include"bean.h"
#include<algorithm>
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *p1 = l1, *p2 = l2;
		ListNode *p=head;
		while (p1 != NULL && p2 != NULL){
			if (p1->val <= p2->val){
				p->next = p1;
				p1 = p1->next;
			}
			else{
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		p->next = p1==NULL?p2:p1;
		return head->next;
	}
	ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1,*p2=l2;
		ListNode *head = NULL,*p=head;
		vector<ListNode*> vec;
		while (p1 != NULL && p2 != NULL){
			if (p1->val <= p2->val){
				p = new ListNode(p1->val);	
				p1 = p1->next;
			}
			else{
				p = new ListNode(p2->val);
				p2 = p2->next;
			}
			vec.push_back(p);
		}
		while (p1 != NULL){
			p = new ListNode(p1->val);
			p1 = p1->next;
			vec.push_back(p);
		}
		while (p2 != NULL){
			p = new ListNode(p2->val);
			p2 = p2->next;
			vec.push_back(p);
		}
		for (int i = 0; i < vec.size()-1; i++){
			vec[i]->next = vec[i + 1];
		}
		return vec[0];
	}
	void test(){
		int a[] = {1,3,8,11,15};
		int b[] = {2,4};
		ListNode *h1 = Utils::arrayToList(a,sizeof(a)/sizeof(int));
		ListNode *h2 = Utils::arrayToList(b,sizeof(b) / sizeof(int));
		cout << mergeTwoLists(h1,h2) << endl;
	}
};