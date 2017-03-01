/*
 * smallestDifference.h
 *
 *  Created on: 2016Äê4ÔÂ17ÈÕ
 *      Author: XIAOWEI
 */

#ifndef SMALLESTDIFFERENCE_H_
#define SMALLESTDIFFERENCE_H_
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference1(vector<int> &A, vector<int> &B) {
    	int dif=A[0]-B[0];
		sort(A.begin(),A.end());
		sort(B.begin(), B.end());
    	dif=getAbs(dif);
    	for(unsigned int i=0; i<A.size(); i++){
    		for(unsigned int j=0; j<B.size(); j++){
    			int d=getAbs(A[i]-B[j]);
    			if(d<dif){
    				dif=d;
    			}
    		}
    	}
        return dif;
    }
	int smallestDifference2(vector<int> &A, vector<int> &B) {
			
		int dif = A[0] - B[0];
		dif = getAbs(dif);
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int i = 0, j = 0;
		for (; i<A.size() && j<B.size();){
			int d = getAbs(A[i]-B[j]);
			if (d<dif){
				dif = d;
			}
			if(A[i] > B[j]){
				j++;
			}
			else{
				i++;
			}
		}
		return dif;
	}
    int getAbs(int n){
    	return n>=0 ? n :-n;
    }
};
#endif /* SMALLESTDIFFERENCE_H_ */
