#include"utils.h"
#include<set>
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int len1 = 0,len2=0;
		ListNode *p1 = headA,*p2=headB;
		while (p1){
			len1++;
			p1 = p1->next;
		}
		while (p2){
			len2++;
			p2 = p2->next;
		}
		p1 = headA;
		p2 = headB;
		if (len1 > len2){
			int k = len1 - len2;	
			while (k--){
				p1 = p1->next;
			}
		}
		else if (len1 < len2){
			int k = len2 - len1;
			while (k--){
				p2 = p2->next;
			}
		}
		while (p1){
			if (p1 == p2)
				return p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		return nullptr;
	}
	ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
		//������Bβ�����ӵ�B��ͷ��㣬ʹ�ÿ���ָ���ҵ������ж��Ƿ񽻲�
		//�����ڵ㵽����ڣ�����㣩�ľ������A��ͷ��㵽����ڵľ���
		if (!headA || !headB)
			return nullptr;
		ListNode *p = headA;
		ListNode *pre=nullptr;
		while (p){
			pre = p;
			p = pre->next;
		}
		ListNode *last = pre;
		pre->next = headB;
		ListNode *slow = headA, *fast = headA,*meet=nullptr;
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
		p = headA;
		while (p && p!=meet){
			p = p->next;
			meet = meet->next;
		}
		last->next = nullptr;
		return p;
	}
	ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
		//ʱ�临�Ӷ�O(nlog(n))���ռ临�Ӷ�ΪO(n)��������Ҫ��
		ListNode *p1 = headA, *p2 = headB;
		set<ListNode*> s;
		while (p1){
			s.insert(p1);
			p1 = p1->next;
		}
		while (p2){
			if (s.find(p2) != s.end())
				return p2;
		}
		return nullptr;
	}
	ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
		//ʱ�临�Ӷ�O(n^2),��������ĿҪ��
		ListNode *p1 = headA, *p2 = headB;
		while(p1){
			p2 = headB;
			while (p2){
				if (p1 == p2)
					return p1;
			}
		}
		return false;
	}
};