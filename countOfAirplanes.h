#include"utils.h"
class Solution {
public:
	/**
	* @param intervals: An interval array
	* @return: Count of airplanes are in the sky.
	*/
	int countOfAirplanes2(vector<Interval> &airplanes) {
		if (airplanes.empty())
			return 0;
		int end = airplanes[0].end;
		for (int i = 0; i < airplanes.size(); i++)
			if (airplanes[i].end > end)
				end = airplanes[i].end;
		vector<int> vec(end + 1);
		for (int i = 0; i < airplanes.size(); i++)
			for (int j = airplanes[i].start; j < airplanes[i].end; j++)
				vec[j]++;
		int count = 0;
		for (int i = 0; i <= end; i++)
			if (count < vec[i])
				count = vec[i];
		return count;
	}
	//ÔËÐÐ³¬Ê±
	int countOfAirplanes1(vector<Interval> &airplanes) {
		if (airplanes.empty())
			return 0;
		map<int, int> m;
		for (int i = 0; i < airplanes.size(); i++)
			for (int j = airplanes[i].start; j < airplanes[i].end; j++)
				m[j]++;
		int count = 0;
		for (pair<int, int> p : m)
			if (p.second > count)
				count = p.second;
		return count;
	}
	int countOfAirplanes(vector<Interval> &airplanes) {
		map<int, int> m;
		set<int> s;
		for (int i = 0; i < airplanes.size(); i++){
			m[airplanes[i].start]++;
			m[airplanes[i].end]++;
			s.insert(airplanes[i].start);
			s.insert(airplanes[i].end);
		}
		int count = 0;
		for (pair<int, int> p : m)
			if (p.second > count)
				count = p.second;
		return count;
	}
	
};