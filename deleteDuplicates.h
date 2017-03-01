#include"utils.h"
class Solution{
public:
	
	ListNode * deleteDuplicates(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode h(0);
		h.next = head;
		ListNode *pre = &h, *p = pre->next;
		while (p){
			int count = 0;
			int temp = p->val;
			while (p && p->val==temp){
				count++;
				p = p->next;
			}
			if (count>1)
				pre->next = p;
			else
				pre = pre->next;
		}
		return h.next;
	}
	void test(){
		int a[] = { 0, 1, 1, 2, 3,3,3 };
		ListNode *h = Utils::arrayToList(a, sizeof(a) / sizeof(int));
		cout << deleteDuplicates(h) << endl;
	}
};