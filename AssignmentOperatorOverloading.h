#pragma warning(disable:4996)
#include"utils.h"
class Solution {
public:
	char *m_pData;
	Solution() {
		this->m_pData = NULL;
	}
	Solution(char *pData) {
		this->m_pData = pData;
	}

	// Implement an assignment operator
	Solution operator=(const Solution &object) {
		if (object.m_pData == NULL){
			this->m_pData = NULL;
		}
		else{
			int len = strlen(object.m_pData);
			char *p = new char[len];
			strcpy(p, object.m_pData);
			this->m_pData = p;
		}
		return *this;
	}
	void test(){
		Solution s1;
		Solution s2("b");
		cout << s2.m_pData << endl;
		s2 = s1;
		cout << (s2.m_pData == NULL) << endl;
	}
};