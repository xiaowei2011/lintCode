/*
 * permute.h
 *
 *  Created on: 2016Äê4ÔÂ10ÈÕ
 *      Author: XIAOWEI
 */
#ifndef PERMUTE_H_
#define PERMUTE_H_
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
    	vector<vector<int> > result;
    	vector<int> vec=nums;
    	permutation(nums,nums.size()-1,0,result);
        return result;
    }
    vector<vector<int> > permuteUnique(vector<int> &nums) {
    	vector<vector<int> > result;
    	vector<int> vec=nums;
    	permutationUnique(nums,nums.size()-1,0,result);
    	return result;
    }
    void permutationUnique(vector<int> &nums,int m,int k,vector<vector<int> > &result){
        if(k==m){
        	if(!contain(result,nums)){
				result.push_back(nums);
        	}
        }else{
    		for(int i=k; i<=m; i++){
    			int temp=nums[k];
    			nums[k]=nums[i];
    			nums[i]=temp;
    			permutationUnique(nums,m,k+1,result);
    			temp=nums[k];
    			nums[k]=nums[i];
    			nums[i]=temp;
    		}
        }
    }
    void permutation(vector<int> &nums,int m,int k,vector<vector<int> > &result){
    	if(k==m){
    		result.push_back(nums);
    	}else{
			for(int i=k; i<=m; i++){
				int temp=nums[k];
				nums[k]=nums[i];
				nums[i]=temp;
				permutation(nums,m,k+1,result);
				temp=nums[k];
				nums[k]=nums[i];
				nums[i]=temp;
			}
		}
    }
    vector<int> nextPermutation(vector<int> &nums){
    	for(unsigned int i=nums.size()-2; i>=0; i--){
    		if(nums[i]<nums[i+1]){
    			int min=i+1;
    			for(unsigned int j=i+2; j<nums.size(); j++){
    				if(nums[i]<nums[j] && nums[j]<nums[min]){
    					min=j;
    				}
    			}
    			swap(nums,i,min);
    			reverse(nums,i+1);
    			return nums;
    		}
    	}
    	reverse(nums,0);
    	return nums;
    }
    void reverse(vector<int> &nums,int k){
    	for(unsigned int i=k,j=nums.size()-1; i<j; i++,j--){
    		swap(nums,i,j);
    	}
    }
    void swap(vector<int> &nums,int k,int m){
    	int temp=nums[k];
    	nums[k]=nums[m];
    	nums[m]=temp;
    }
    bool contain(const vector<vector<int> > &vec,const vector<int> &nums){
    	for(unsigned int i=0; i<vec.size(); i++){
    		bool flag=true;
    		if(vec[i].size()!=nums.size()){
    			flag=false;
    		}else{
				for(unsigned int j=0; j<vec[i].size(); j++){
					if(vec[i][j]!=nums[j]){
						flag=false;
						break;
					}
				}
    		}
    		if(flag){
    			return true;
    		}
    	}
    	return false;
    }
    static void print(const vector<vector<int> > &nums){
    	for(unsigned int i=0; i<nums.size(); i++){
    	    print(nums[i]);
    	}
    }
    static void print(const vector<int> &nums){
    	cout<<"[";
    	for(unsigned int i=0; i<nums.size(); i++){
    		cout<<nums[i]<<" ";
    	}
    	cout<<"]"<<endl;
    }
};
#endif /* PERMUTE_H_ */
