#include"utils.h"
#include<algorithm>
#include<numeric>
class Solution {
public:
	/**
	* @param n: an integer
	* @return: a boolean which equals to true if the first player will win
	*/
	/*
		�㷨˼·��
		����dp[i]��ʾ��i��end��ȡ�������ֵ
		��������i����������ѡ��
		1.��ȡvalues[i]���Է�����ȡvalues[i + 1] ����values[i + 1] + values[i + 2]
		���Է�ȡvalues[i + 1] �� ������ֻ�ܴ� i + 2 ��end��ȡ��������ȡ�����ֵ��dp[i + 2], ע�⣺�Է���ѡȡ�Ľ��һ����ʹ�������Ժ�ѡȡ��ֵ��С
		���Է�ȡvalues[i + 1] + values[i + 2]������ֻ�ܴ�i + 3��end��ȡ��������ȡ�����ֵ��dp[i + 3]��
		��ʱ��dp[i] = values[i] + min(dp[i + 2], dp[i + 3]), ע�⣺�Է���ѡȡ�Ľ��һ����ʹ�������Ժ�ѡȡ��ֵ��С
		2.��ȡvalues[i] + values[i + 1], �Է���ȡvalues[i + 2] ����values[i + 2] + values[i + 3]
		���Է�ȡvalues[i + 2]������ֻ�ܴ�i + 3��end��ȡ������ȡ�����ֵ��dp[i + 3]
		���Է�ȡvalues[i + 2] + values[i + 3]������ֻ�ܴ�i + 4��end��ȥ������ȡ�����ֵ��dp[i + 4]
		��ʱ��dp[i] = values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4])
	*/
	bool firstWillWinII(vector<int> &values) {
		int len = values.size();
		if (len < 3)
			return true;
		int *dp = new int[len + 1];
		dp[len] = 0;
		dp[len - 1] = values[len - 1];
		dp[len - 2] = values[len - 2] + values[len - 1];
		dp[len - 3] = values[len - 3] + values[len - 2];
		for (int i = len - 4; i >= 0; i--){
			dp[i] = values[i] + min(dp[i+2],dp[i+3]);
			dp[i] = max(dp[i], values[i]+values[i+1]+min(dp[i+3],dp[i+4]));
		}
		int sum = accumulate(values.begin(),values.end(),0);
		int a = dp[0];
		delete[] dp;
		return a>sum - a;
	}

	//���г�ʱ��Ҫ��O(1)��ʱ�临�Ӷ�
	bool firstWillWin1(int n) {
		if (n < 3)
			return true;
		return !firstWillWin1(n - 1) || !firstWillWin1(n - 2);
	}

	bool firstWillWin(int n) {
		return n % 3 != 0;
	}

	bool firstWillWin2(int n) {
		if (n < 1)
			return false;
		vector<bool> vec(n+1, true);
		for (int i = 3; i < n+1; i++){
			vec[i] = !vec[i - 1] || !vec[i - 2];
		}
		return vec[n];
	}
	void test(){
		int a[] = { 1, 2, 4, 8 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << firstWillWinII(vec) << endl;
	}
};