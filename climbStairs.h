class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		//¶¯Ì¬¹æ»®
		int *sum = new int[n+1]{0};
		sum[0] = 1;
		sum[1] = 1;
		for (int i = 2; i < n+1; i++){
			sum[i] = sum[i - 1] + sum[i - 2];
		}
		return sum[n];
	}
};
