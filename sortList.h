#include"utils.h"
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		//¹é²¢ÅÅÐò
		return mergeList(head);
	}

	ListNode *mergeList(ListNode *head){
		if (!head || !head->next)
			return head;
		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = mergeList(slow->next);
		slow->next = nullptr;
		slow = mergeList(head);
		ListNode* p = merge(slow, fast);
		return p;
	}

	ListNode *merge(ListNode *p1,ListNode *p2){
		ListNode h(-1);
		ListNode *p = &h;
		while (p1 && p2){
			if (p1->val <= p2->val){
				p->next = p1;
				p = p1;
				p1 = p1 -> next;
			}
			else{
				p->next = p2;
				p = p2;
				p2 = p2->next;
			}
		}
		if (p1)
			p->next = p1;
		if (p2)
			p->next = p2;
		return h.next;
	}
	
	ListNode *sortList2(ListNode *head) {
		//¿ìËÙÅÅÐò
		ListNode *p = head;
		while (p && p->next)
			p = p->next;
		quickSort(head, nullptr);
		return head;
	}
	void quickSort(ListNode *start, ListNode *end){
		if (start != end){
			ListNode *p = start;
			ListNode *q = p->next;
			int key = p->val;
			while (q != end){
				if (q->val < key){
					p = p->next;
					swap(p, q);
				}
				q = q->next;
			}
			swap(p, start);
			quickSort(start, p);
			quickSort(p->next, end);
		}
	}
	void swap(ListNode *p, ListNode *q){
		int temp = p->val;
		p->val = q->val;
		q->val = temp;
	}
	ListNode *sortList1(ListNode *head) {
		//Ã°ÅÝÅÅÐò
		if (!head)
			return nullptr;
		ListNode h(-1);
		h.next = head;
		ListNode *ppre=&h,*pre = head,*p=head->next,*p1=head->next;
		while (p1){
			p = p1;
			while (p){
				if (p->val<pre->val){
					ppre->next = p;
					pre->next = p->next;
					p->next = pre;
					ppre = p;
					p = pre->next;
				}
				else{
					ppre = pre;
					pre = p;
					p = p->next;
				}
			}
			p1 = p1->next;
		}
		return h.next;
	}
	void test(){
		int a[] = { 1, 3, 2, 6,5,7,2 };
		int b[] = { 2, 3, 1 };
		ListNode *h = Utils::arrayToList(a, sizeof(a) / sizeof(int));
		ListNode *h1 = Utils::arrayToList(b, sizeof(b) / sizeof(int));
		cout << sortList(h) << endl;
	}
};