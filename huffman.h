#include"Utils.h"
#include<set>
#include<algorithm>
#include<functional>
int huffman(const vector<int> &plank){
	vector<int> vec(plank.begin(), plank.end());
	sort(vec.begin(), vec.end());
	int sum = 0;
	int id = 0;
	while (vec.size()-id > 1){
		int temp = vec[id] + vec[id+1];
		sum += temp;
		int j = id+1;
		while (j<vec.size()-1 && temp>vec[j+1]){
			vec[j] = vec[++j];
		}
		vec[j] = temp;
		id++;
	}
	return sum;
}
int huffman1(const vector<int> &plank){
	//时间复杂度略高
	vector<int> vec(plank.begin(),plank.end());
	sort(vec.begin(),vec.end(),greater<int>());
	int sum = 0;
	while (vec.size() > 1){
		int temp = vec.back();
		vec.pop_back();
		temp += vec.back();
		vec.pop_back();
		sum += temp;
		vec.push_back(temp);
		sort(vec.begin(), vec.end(), greater<int>());
	}
	return sum;
}
void test(){
	int a[] = {8,5,8,3 };
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	cout << huffman(vec) << endl;
}