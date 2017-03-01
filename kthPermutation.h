/*
 * kthPermutation.h
 *
 *  Created on: 2016Äê4ÔÂ9ÈÕ
 *      Author: XIAOWEI
 */

#ifndef KTHPERMUTATION_H_
#define KTHPERMUTATION_H_
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
class kthPermutation {
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
public:
    string getPermutation(int n, int k) {
    	string s="";
    	int fa=getFactorial(n);
    	if(k<1 || k>fa){
    		return NULL;
    	}
    	bool *used=new bool[n+1]{false};
    	for(int i=1;i<=n;i++){
			fa=getFactorial(n-i);
			int a=k/fa;
			int b=k%fa;
			int c=getKthNum(n,a+1,used);
			string cs;
			stringstream stream;
			stream<<c;
			stream>>cs;
			used[c]=1;
			s+= cs;
			k=b;
    	}
    	delete[] used;
    	return s;
    }
    int getKthNum(int n,int k,bool used[]){
    	for(int i=1; i<=n; i++){
    		cout<<i<<":"<<k<<endl;
    		if(!used[i]){
    			if(k==1){
    				return i;
    			}
    			k--;
    		}
    	}
    	return -1;
    }
    int getFactorial(int n){
    	int result=1;
    	while(n>1){
    		result*=n;
    		n--;
    	}
    	return result;
    }
};
#endif /* KTHPERMUTATION_H_ */
