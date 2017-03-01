#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include"utils.h"
#include"bean.h"
using namespace std;
class Solution {
public:

	void test(){
		int a[] = { 1, 2, 3 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		Utils::print(vec);
		cout << houseRobberII(vec) << endl;
		test1();
		vec.push_back(5);
	}
	void test1(){
		TreeNode n1(3), n2(2), n3(3), n4(3), n5(1);
		n1.left = &n2;
		n1.right = &n3;
		n2.right = &n4;
		n3.right = &n5;
		/*
		map<TreeNode*, TreeNode*> m;
		parent(&n1,m);
		cout << &n1 << endl;
		Utils::print(m);
		*/
		cout<<"->"<<houseRobberIII(&n1)<<endl;
	}
	map<TreeNode*, int> sum;
	int houseRobberIII(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (sum.find(root) != sum.end())
			return sum[root];
		int dp0 = root->val;
		if (root->left != NULL){
			dp0 += houseRobberIII(root->left->left);
			dp0 += houseRobberIII(root->left->right);
		}
		if (root->right != NULL){
			dp0 += houseRobberIII(root->right->left);
			dp0 += houseRobberIII(root->right->right);
		}
		int dp1 = houseRobberIII(root->left) + houseRobberIII(root->right);
		sum[root] = max(dp0, dp1);
		return sum[root];
	}
	int houseRobber3(TreeNode* root) {
		map<TreeNode*, int> dp;
		traverse1(root, dp);
		return dp[root];
	}
	void traverse1(TreeNode* root, map<TreeNode*, int> &dp){
		if (root != NULL){
			traverse1(root->left, dp);
			traverse1(root->right, dp);
			int dpl = 0, dpll = 0, dplr = 0, dpr = 0, dprl = 0, dprr = 0;
			if (dp.find(root->left) != dp.end()){
				dpl = dp[root->left];
				if (dp.find(root->left->left) != dp.end()){
					dpll = dp[root->left->left];
				}
				if (dp.find(root->left->right) != dp.end()){
					dplr = dp[root->left->right];
				}
			}
			if (dp.find(root->right) != dp.end()){
				dpr = dp[root->right];
				if (dp.find(root->right->left) != dp.end()){
					dprl = dp[root->right->left];
				}
				if (dp.find(root->right->right) != dp.end()){
					dprr = dp[root->right->right];
				}
			}
			int dp0 = dpll + dplr + dprl + dprr;
			int dp1 = dpl + dpr;
			dp[root] = max(root->val + dp0, dp1);
		}
	}
	int houseRobberIII2(TreeNode* root) {
		//结果不对，没考虑左节点对父节点的影响
		map<TreeNode*, TreeNode*> p;
		parent(root, p);
		map<TreeNode*, int> dp;
		traverse(root, p, dp);
		Utils::print(dp);
		return 0;
	}
	void traverse(TreeNode* root, map<TreeNode*, TreeNode*> &p, map<TreeNode*, int> &dp){
		if (root != NULL){
			int p1 = 0, p2 = 0,p3=0;
			int n1 = 0, n2 = 0, n3 = 0,n0=root->val;
			if (p.find(root) != p.end()){
				p1 = dp[root];
				n1 = p[root]->val;
				if (p.find(p[root]) != p.end()){
					p2 = dp[p[root]];
					n2 = p[p[root]]->val;
					if (p.find(p[p[root]]) != p.end()){
						p3 = dp[p[p[root]]];
						n3 = p[p[p[root]]]->val;
					}
				}
			}
			dp[root] = max(n1+p3,n0+p2);
			traverse(root->left, p,dp);
			traverse(root->right, p,dp);
		}
	}
	void parent(TreeNode* root,map<TreeNode*,TreeNode*> &m){
		if (root != NULL){
			if (root->left != NULL){
				m[root->left] = root;
			}
			if (root->right != NULL){
				m[root->right] = root;
			}
			parent(root->left,m);
			parent(root->right,m);
		}
	}
	int houseRobberII(vector<int>& nums) {
		int len = nums.size();
		if (len < 1){
			return 0;
		}
		else if (len == 1){
			return nums[0];
		}
		else if (len == 2){
			return max(nums[0], nums[1]);
		}
		int *sum = new int[len];
		sum[0] = nums[0];
		sum[1] = max(nums[0], nums[1]);
		sum[2] = max(nums[0] + nums[2], nums[1]);
		for (int i = 3; i < len - 1; i++){
			sum[i] = max(sum[i - 3] + nums[i - 1], sum[i - 2] + nums[i]);
		}
		int r1 = sum[len - 2];
		sum[0] = 0;
		sum[1] = nums[1];
		sum[2] = max(nums[2], nums[1]);
		for (int i = 3; i < len; i++){
			sum[i] = max(sum[i - 3] + nums[i - 1], sum[i - 2] + nums[i]);
		}
		return max(sum[len - 1], r1);
	}
	long long houseRobber(vector<int> A) {
		int len = A.size();
		if (len < 1){
			return 0;
		}
		else if (len == 1){
			return A[0];
		}
		else if (len == 2){
			return max(A[0], A[1]);
		}
		long long dp1 = A[0];
		long long dp2 = max(A[0], A[1]);
		long long dp3 = max(A[0] + A[2], A[1]);
		for (int i = 3; i < len; i++){
			long long temp = max(dp1 + A[i - 1], dp2 + A[i]);
			dp1 = dp2;
			dp2 = dp3;
			dp3 = temp;
		}
		return dp3;
	}
	long long houseRobber1(vector<int> A) {
		int len = A.size();
		if (len < 1){
			return 0;
		}
		else if (len == 1){
			return A[0];
		}
		else if (len == 2){
			return max(A[0], A[1]);
		}
		long long *sum = new long long[len];
		sum[0] = A[0];
		sum[1] = max(A[0], A[1]);
		sum[2] = max(A[0] + A[2], A[1]);
		for (int i = 3; i < len; i++){
			sum[i] = max(sum[i - 3] + A[i - 1], sum[i - 2] + A[i]);
		}
		return sum[len - 1];
	}
	long long houseRobber2(vector<int> A) {
		//结果不对
		int len = A.size();
		if (len < 1){
			return 0;
		}
		else if (len == 1){
			return A[0];
		}
		int pp = A[0];
		int p, id;
		if (A[0]>A[1]){
			p = A[0];
			id = 0;
		}
		else{
			p = A[1];
			id = 1;
		}
		for (int i = 2; i < len; i++){
			if (id != i - 1){
				if (pp + A[i] > p){
					pp = p;
					p = pp + A[i];
					id = i;
				}
				else{
					pp = p;
				}
			}
			else{
				pp = p;
			}
		}
		return p;
	}
};