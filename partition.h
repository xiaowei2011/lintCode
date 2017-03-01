#include"utils.h"
class Solution {
public:

	ListNode *partition(ListNode *head, int x) {
		if (!head || !head->next)
			return head;
		ListNode h(-1);
		h.next = head;
		ListNode *p = head, *pre = &h;
		while (p && p->val < x){
			pre = p;
			p = p->next;
		}
		if (p){
			ListNode *t1 = pre, *t2 = p;
			while (p){
				if (p->val < x){
						t1->next = p;
						pre->next = p->next;
						p->next = t2;
						t1 = t1->next;
						p = pre->next;
				}
				else{
					pre = p;
					p = p->next;
				}
			}
		}
		return h.next;
	}
	ListNode *partition1(ListNode *head, int x) {
		if (!head || !head->next)
			return head;
		ListNode h(-1);
		h.next = head;
		ListNode *p = head,*pre=&h;
		while (p && p->val < x){
			pre = p;
			p = p->next;
		}
		if (p){
			ListNode *t1 = pre,*t2=p;
			while (p){
				if (p->val < t2->val){
					if (p->val >= x){
						t1->next = p;
						pre->next = p->next;
						p->next = t2;
						t2 = t1->next;
						p = pre->next;
					}
					else{
						t1->next = p;
						pre->next = p->next;
						p->next = t2;
						t1 = t1->next;
						p = pre->next;
					}
				}
				else{
					pre = p;
					p = p->next;
				}
			}
		}
		return h.next;
	}
	void test(){
		int a[] = { 1, 4, 3, 2, 5, 2 };
		ListNode *h = Utils::arrayToList(a, sizeof(a) / sizeof(int));
		cout << partition(h,3) << endl;
	}
};
