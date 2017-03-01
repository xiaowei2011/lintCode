#include"utils.h"
#include<tuple>
class Solution {
public:
	/**
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	//一神奇的算法
	int maxProfitIII(vector<int> &prices) {
		
	}
	//一种有点绕的算法
	int maxProfitIII2(vector<int> &prices) {
		if (prices.size() < 2)
			return 0;
		tuple<vector<int>::iterator, vector<int>::iterator> interval1 = findMaxProfit(
			prices.begin(),prices.end());
		tuple<vector<int>::iterator, vector<int>::iterator> interval2 = findMinProfit(
			get<0>(interval1), get<1>(interval1));
		int pro = *get<1>(interval1)-*get<0>(interval1);
		int pro1 = *get<0>(interval2)-*get<1>(interval2);
		interval2 = findMaxProfit(prices.begin(), get<0>(interval1)+1);
		int pro2 = *get<1>(interval2)-*get<0>(interval2);
		pro1 = pro1 > pro2 ? pro1 : pro2;
		interval2 = findMaxProfit(get<1>(interval1), prices.end());
		pro2 = *get<1>(interval2)-*get<0>(interval2);
		pro1 = pro1 > pro2 ? pro1 : pro2;
		return pro + pro1;
	}
	tuple<vector<int>::iterator, vector<int>::iterator> findMaxProfit(
		vector<int>::iterator begin, vector<int>::iterator end){
		vector<int>::iterator minIndex = begin;
		int maxPro = 0;
		tuple<vector<int>::iterator, vector<int>::iterator> interval(begin, begin);
		for (vector<int>::iterator it = begin + 1; it < end; it++){
			if (*it < *minIndex){
				minIndex = it;
			}
			else{
				if (*it - *minIndex>maxPro){
					get<0>(interval) = minIndex;
					get<1>(interval) = it;
					maxPro = *it - *minIndex;
				}
			}
		}
		return interval;
	}

	tuple<vector<int>::iterator, vector<int>::iterator> findMinProfit(
		vector<int>::iterator begin, vector<int>::iterator end){
		vector<int>::iterator maxIndex = begin;
		int minPro = 0;
		tuple<vector<int>::iterator, vector<int>::iterator> interval(begin, begin);
		for (vector<int>::iterator it = begin + 1; it < end; it++){
			if (*it > *maxIndex){
				maxIndex = it;
			}
			else{
				if (*maxIndex - *it > minPro){
					get<0>(interval) = maxIndex;
					get<1>(interval) = it;
					minPro = *maxIndex - *it;
				}
			}
		}
		return interval;
	}

	int maxProfitIII1(vector<int> &prices) {
		int len = prices.size();
		if (len < 2)
			return 0;
		int pri = prices[len-1];
		vector<int> maxPos(len);
		for (int i = len - 2; i >= 0; i--){
			if (pri - prices[i]>maxPos[i + 1])
				maxPos[i] = pri - prices[i];
			else
				maxPos[i] = maxPos[i + 1];
			if (prices[i] > pri)
				pri= prices[i];
		}
		pri = prices[0];
		int maxPre = 0;
		int ret = 0;
		for (int i = 1; i < len; i++){
			if (prices[i] - pri > maxPre)
				maxPre = prices[i] - pri;
			if (prices[i]<pri)
				pri = prices[i];
			if (maxPre + maxPos[i] > ret)
				ret=maxPre+maxPos[i];
		}
		return ret;
	}

	int maxProfitII(vector<int> &prices) {
		int sum = 0;
		for (int i = 1; i < prices.size(); i++){
			if (prices[i] - prices[i-1] > 0){
				sum += prices[i] - prices[i - 1];
			}
		}
		return sum;
	}

	//进一步优化
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2)
			return 0;
		int minPrice = prices[0];
		int max = 0;
		for (int i = 1; i < prices.size(); i++){
			if (prices[i] - minPrice > max){
				max = prices[i] - minPrice;
			}
			if (prices[i] < minPrice)
				minPrice = prices[i];
		}
		return max;
	}
	//时间复杂度降到了O(n),空间复杂度为O(n)
	int maxProfit2(vector<int> &prices) {
		int len = prices.size();
		if (len < 1)
			return 0;
		vector<int>  minPrices(len);
		minPrices[0] = prices[0];
		for (int i = 1; i < len; i++){
			if (prices[i] < minPrices[i - 1])
				minPrices[i] = prices[i];
			else
				minPrices[i] = minPrices[i - 1];
		}
		int min = 0;
		for (int i = 0; i < len; i++){
			if (prices[i] - minPrices[i]>min)
				min = prices[i] - minPrices[i];
		}
		return min;
	}
	//枚举法，超时
	int maxProfit1(vector<int> &prices) {
		int max = 0;
		for (int i = 0; i < prices.size(); i++){
			for (int j = i+1; j < prices.size(); j++){
				if (prices[j] - prices[i]>max)
					max = prices[j] - prices[i];
			}
		}
		return max;
	}
	void test(){
		int a[] = { 2, 1, 2, 0, 1 };
		vector<int> vec(a, a + sizeof(a) / sizeof(int));
		cout << maxProfitIII(vec)<<endl;
	}
};
