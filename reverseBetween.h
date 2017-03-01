#include"utils.h"
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (!head || !head->next || m == n)
			return head;
		ListNode h(-1);
		h.next = head;
		ListNode *pre = &h, *p = head;
		int count = 0;
		ListNode *p1,*p2,*p3;
		p1 = p2 = p3 = nullptr;
		while (p){
			count++;
			if (count == m){
				p1 = pre;
				p2 = p;
			}
			if (count == n){
				p3 = p;
			}
			pre = p;
			p = p->next;
		}
		while (p2 != p3){
			p = p2->next;
			p2->next = p3->next;
			p3->next = p2;
			p2 = p;
		}
		p1->next = p3;
		return h.next;
	}
	ListNode *reverseBetween1(ListNode *head, int m, int n) {
		if (!head || !head->next || m==n)
			return head;
		vector<ListNode*> vec;
		ListNode *p = head;
		while (p){
			vec.push_back(p);
			p = p->next;
		}
		for (int i = m; i < n; i++){
			vec[i]->next = vec[i - 1];
		}
		if (m>1)
			vec[m - 2]->next = vec[n - 1];
		vec[m - 1]->next = vec[n];
		return m>1?vec[0]:vec[n-1];
	}
	void test(){
		int a[] = { 1,2,3,4,5 };
		ListNode *h = Utils::arrayToList(a, sizeof(a) / sizeof(int));
		cout << reverseBetween(h, 1, 4)<<endl;
	}
};