#include"utils.h"
class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head)
			return head;
		ListNode *p = head;
		int len = 1;
		while (p->next){
			len++;
			p = p->next;
		}
		p->next=head;
		k %= len;
		p = head;
		int count = 1;
		while (count<len-k){
			p = p->next;
			count++;
		}
		head = p->next;
		p->next = NULL;
		return head;
	}
	ListNode *rotateRight1(ListNode *head, int k) {
		if (!head || !head->next)
			return head;
		int n = 0;
		ListNode *p = head;
		while (p){
			n++;
			p = p->next;
		}
		ListNode h(-1);
		h.next = head;
		ListNode *pre = &h;
		p = head;
		while (p && n>k){
			pre = p;
			p = p->next;
			n--;
		}
		pre->next = NULL;
		head = p;
		while (p){
			pre = p;
			p = p->next;
		}
		pre->next = h.next;
		return head;
	}
};