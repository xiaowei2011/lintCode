#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	* @param pages: a vector of integers
	* @param k: an integer
	* @return: an integer
	*/
	int copyBooks(vector<int> &pages, int k) {
		int sum = 0;
		for (unsigned int i = 0; i < pages.size(); i++){
			sum += pages[i];
		}
		int l = 1,h=sum;
		while (l < h){
			int mid = (l + h) / 2;
			if (check(pages, mid, k)){
				h = mid;
			}
			else{
				l = mid+1;
			}
		}
		return l;
	}
	bool check(const vector<int> &pages,int p,int k){
		int count = 0;
		int sum = 0;
		int i = 0;  
		while (i<pages.size()){
			if (sum + pages[i] <= p){
				sum += pages[i];
				i++;
			}
			else if (pages[i] <= p){
				count++;
				sum = 0;
			}
			else{
				return false;
			}
		}
		if (sum != 0){
			count++;
		}
		return count <= k;
	}
	void test(){
		int a[] = {2,3,4};
		vector<int> vec(a,a+sizeof(a)/sizeof(int));
		int n = copyBooks(vec,2);
		cout << n << endl;
	}
};