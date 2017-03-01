#include"utils.h"
#include<algorithm>
class Solution {
public:
	/**
	* Insert newInterval into intervals.
	* @param intervals: Sorted interval list.
	* @param newInterval: new interval.
	* @return: A new interval list.
	*/
	//此代码流程太乱，不能忍
	vector<Interval> insert1(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> vec;
		if (intervals.empty()){
			vec.push_back(newInterval);
			return vec;
		}
		if (intervals.front().start > newInterval.end){
			vec.push_back(newInterval);
			vec.insert(vec.end(), intervals.begin(), intervals.end());
			return vec;
		}
		if (intervals.back().end < newInterval.start){
			vec.insert(vec.end(), intervals.begin(), intervals.end());
			vec.push_back(newInterval);
			return vec;
		}
		int i = 0;
		for (; i < intervals.size() && intervals[i].end < newInterval.start; i++){
			vec.push_back(intervals[i]);
		}
		int start = min(newInterval.start, intervals[i].start);
		for (; i < intervals.size() && intervals[i].end < newInterval.end; i++);
		int end;
		if (i == intervals.size()){
			end = newInterval.end;
			vec.push_back(Interval(start, end));
		}
		else{
			if (intervals[i].start > newInterval.end){
				end = newInterval.end;
				vec.push_back(Interval(start, end));
				vec.insert(vec.end(), intervals.begin() + i, intervals.end());
			}
			else{
				end = intervals[i].end;
				vec.push_back(Interval(start, end));
				vec.insert(vec.end(), intervals.begin() + i+1, intervals.end());
			}
		}
		return vec;
	}

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> vec;
		if (intervals.empty()){
			vec.push_back(newInterval);
			return vec;
		}
		int i;
		for (i = 0; i < intervals.size() && intervals[i].start < newInterval.start; i++);
		intervals.insert(intervals.begin() + i,newInterval);
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (i=0; i < intervals.size(); i++){
			if (intervals[i].start <= end){
				end = max(end,intervals[i].end);
			}
			else{
				vec.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		vec.push_back(Interval(start, end));
		return vec;
	}
	vector<Interval> insert2(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> vec;
		if (intervals.empty()){
			vec.push_back(newInterval);
			return vec;
		}
		int i;
		for (i = 0; i < intervals.size() && intervals[i].start < newInterval.start; i++);
		intervals.insert(intervals.begin() + i, newInterval);
		for (i = 0; i < intervals.size()-1; i++){
			if (intervals[i + 1].start <= intervals[i].end){
				intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
				intervals.erase(intervals.begin() + i + 1);
				i--;
			}
		}
		return intervals;
	}
	bool compare(const Interval in1,const Interval in2){
		if (in1.start == in2.start)
			return in1.end > in2.start;
		else
			return in1.start > in2.start;
	}
	void test(){
		vector<Interval> vec = { Interval(1, 5), Interval(6, 8)};
		Utils::print(insert2(vec,Interval(2,3)));
	}
};