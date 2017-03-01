#include"utils.h"
class Solution {
public:
	
	void reorderList(ListNode *head) {
		if (!head || !head->next)
			return;
		ListNode *slow = head, *fast = head;
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = reverse(slow->next);
		slow->next = nullptr;
		slow = head;
		while (slow && fast){
			ListNode *p1 = slow->next;
			slow->next = fast;
			slow = p1;
			ListNode *p2 = fast->next;
			fast->next = p1;
			fast = p2;
		}
	}
	ListNode *reverse(ListNode *head){
		ListNode *p = head,*pre=nullptr;
		while (p){
			ListNode *temp = p->next;
			p->next = pre;
			pre = p;
			p = temp;
		}
		return pre;
	}
	void test(){
		int a[] = { 1, 2, 3 };
		ListNode *h = Utils::arrayToList(a,3);
		reorderList(h);
		cout << h << endl;
	}
};
