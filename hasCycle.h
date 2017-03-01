#include"utils.h"
#include<set>
class Solution {
public:
	bool hasCycle(ListNode *head) {
		//两根指针
		ListNode *fast = head, *slow = head;
		while (fast){
			fast = fast->next;
			if (!fast)
				return false;
			fast = fast->next;
			slow = slow->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
	bool hasCycle2(ListNode *head) {
		//另一种简洁写法
		ListNode *fast = head, *slow = head;
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
	bool hasCycle1(ListNode *head) {
		//题目要求不使用额外空间，不满足要求
		ListNode *p = head;
		set<ListNode*> s;
		while (p){
			if (s.find(p) == s.end())
				s.insert(p);
			else
				return true;
			p = p->next;
		}
		return false;
	}
};