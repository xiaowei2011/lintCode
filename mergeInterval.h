#include<iostream>
#include<vector>
#include<algorithm>
#include"bean.h"
#include"utils.h"
using namespace std;
class Solution {
public:
	
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ret;
		int len = intervals.size();
		if (len < 1){
			return ret;
		}
		sort(intervals.begin(), intervals.end(), compare);
		//Utils::print(intervals);
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (int i = 0; i < len;i++){
			if (intervals[i].start<=end){
				end = max(end, intervals[i].end);
			}
			else{
				Interval in(start, end);
				ret.push_back(in);
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		Interval in(start, end);
		ret.push_back(in);
		return ret;
	}
	vector<Interval> merge3(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), compare);
		//Utils::print(intervals);
		for (int i = 1; i < intervals.size();){
			if (intervals[i].start <= intervals[i - 1].end){
				intervals[i - 1].end = max(intervals[i - 1].end, intervals[i].end);
				intervals.erase(intervals.begin()+i);
			}
			else{
				i++;
			}
		}
		return intervals;
	}
	static bool compare(const Interval &in1,const Interval &in2){
		return in1.start < in2.start;
	}
	vector<Interval> merge1(vector<Interval> &intervals) {
		int start = INT_MAX, end = INT_MIN;
		for (auto in : intervals){
			if (in.start < start)
				start = in.start;
			if (in.end > end)
				end = in.end;
		}
		int len = end - start + 1;
		bool *a = new bool[len]{false};
		for (auto in : intervals){
			for (int i = in.start-start; i <= in.end-start; i++){
				a[i] = true;
			}
		}
		Utils::print(a, len);
		vector<Interval> result;
		for (int i = 0; i < len-1; i++){
			int s=start, e=start;
			if (i == 0 && a[i])
				s = i+start;
			else if ((!a[i] && a[i + 1]))
				s = i + 1+start;
			if (i == len - 2 && a[i + 1]){
				e = i + 1 + start;
				Interval in(s, e);
				result.push_back(in);
			}
			else if (a[i] && !a[i + 1]){
				e = i + start;
				Interval in(s, e);
				result.push_back(in);
			}
		}
		return result;
	}
	vector<Interval> merge2(vector<Interval> &intervals) {
		//时间复杂度为n^2,输出顺序乱了，通不过
		for (int i = 0; i < intervals.size();){
			bool flag = true;
			for (int j = i + 1; j < intervals.size();){
				if ((intervals[i].end >= intervals[j].start && 
					intervals[i].start <= intervals[j].start) || 
					(intervals[j].end >= intervals[i].start &&
					intervals[j].start <= intervals[i].start)){
					intervals[i].start = min(intervals[i].start, intervals[j].start);
					intervals[i].end = max(intervals[i].end, intervals[j].end);
					intervals.erase(intervals.begin()+j);
					flag = false;
				}
				else{
					j++;
				}
			}
			if (flag){
				i++;
			}
		}
		return intervals;
	}
	void test(){
		Interval in1(2, 3), in2(2, 2), in3(3,3), in4(1, 3), in5(5, 7), in6(2, 2), in7(4, 6);
		vector<Interval> vec;
		vec.push_back(in1);
		vec.push_back(in2);
		vec.push_back(in3);
		vec.push_back(in4);
		vec.push_back(in5);
		vec.push_back(in6);
		vec.push_back(in7);
		/*
		*/
		Utils::print(vec);
		vector<Interval> vec2 = merge(vec);
		Utils::print(vec2);
	}
};