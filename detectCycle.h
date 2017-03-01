#include"utils.h"
#include<set>
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *p = head;
		ListNode *slow = head, *fast = head, *meet = nullptr;
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				meet = slow;
				break;
			}
		}
		if (!meet)
			return nullptr;
		while (p && p != meet){
			p = p->next;
			meet = meet->next;
		}
		return p;
	}
	ListNode *detectCycle1(ListNode *head) {
		//使用了额外空间，不满足题目要求
		ListNode *p = head;
		set<ListNode*> s;
		while (p){
			if (s.find(p) == s.end())
				s.insert(p);
			else
				return p;
			p = p->next;
		}
		return nullptr;
	}
};