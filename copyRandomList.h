#include"utils.h"
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		//一种神奇的算法，时间复杂度O(n)
		if (!head)
			return nullptr;
		RandomListNode *p = head,*q=nullptr;
		while (p){
			RandomListNode *next = p->next;
			q = new RandomListNode(p->label);
			p->next = q;
			q->next=next;
			q->random = p->random;
			p = next;
		}
		RandomListNode *ret = head->next;
		p = head;
		while (p){
			if (p->next->random){
				p->next->random = p->next->random->next;
			}
			p = p->next->next;
		}
		p = head;
		while (p){
			q = p->next;
			p->next = p->next->next;
			if (p->next)
				q->next = p->next->next;
			else
				q->next = nullptr;
			p = p->next;
		}
		return ret;
	}
	RandomListNode *copyRandomList2(RandomListNode *head) {
		//时间复杂度O(n^2)略高
		RandomListNode h(-1);
		RandomListNode *p = head, *p1 = &h;
		while (p){
			p1->next = new RandomListNode(p->label);
			p = p->next;
			p1 = p1->next;
		}
		p = head;
		p1 = h.next;
		while (p){
			if (p->random){
				RandomListNode *cur = head;
				RandomListNode *cur1 = h.next;
				while (cur){
					if (p->random == cur)
						p1->random = cur1;
					cur = cur->next;
					cur1 = cur1->next;
				}
			}
			p = p->next;
			p1 = p1->next;
		}
		return h.next;
	}

	RandomListNode *copyRandomList1(RandomListNode *head) {
		RandomListNode h(-1);
		RandomListNode *p=head,*p1=&h;
		vector<RandomListNode*> v,v1;
		while (p){
			p1->next = new RandomListNode(p->label);
			v.push_back(p);
			v1.push_back(p1->next);
			p = p->next;
			p1 = p1->next;
		}
		for (int i = 0; i < v.size(); i++){
			if (!v[i]->random)
				v1[i]->random = nullptr;
			else{
				for (int j = 0; j < v.size(); j++){
					if (v[i]->random == v[j])
						v1[i]->random = v1[j];
				}
			}
		}
		return h.next;
	}
	void test(){
		RandomListNode n1(-1);
		cout << &n1 << endl;
		cout << copyRandomList(&n1) << endl;
	}
};