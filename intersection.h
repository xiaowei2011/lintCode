#include"utils.h"
#include<set>
#include<algorithm>
class Solution {
public:
	
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		set<int> s1, s2;
		for (int i = 0; i < nums1.size(); i++){
			s1.insert(nums1[i]);
		}
		for (int i = 0; i < nums2.size(); i++){
			s2.insert(nums2[i]);
		}
		for (set<int>::iterator it = s1.begin(); it != s1.end(); it++){
			if (s2.find(*it) != s2.end()){
				ret.push_back(*it);
			}
		}
		return ret;
	}
	vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();){
			if (nums1[i] == nums2[j]){
				if (find(ret.begin(), ret.end(), nums1[i]) == ret.end())
				ret.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
				i++;
			else
				j++;
		}
		return ret;
	}
	vector<int> intersectionII(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();){
			if (nums1[i] == nums2[j]){
				ret.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j]){
				i++;
			}
			else{
				j++;
			}
		}
		return ret;
	}
};