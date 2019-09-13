#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <map>
#include <math.h>
#include <stack>
#include <array>
#include <deque>
using namespace std;



class Solution {
public:

	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int max = -2147483647;
		int temp = 0;


		for (int i = 0; i < len; ++i) {
			if(temp > 0){
				temp += nums[i];
			}
			else {
				temp = nums[i];
			}
			max = std::max(max, temp);
			
		}
		return max;
	}

};

int main() {
	//vector<int> data = vector<int>({ -2,-1 });
	//int res = Solution().maxSubArray(data);
	//cout << res << endl;
	
	int **p = new int*[5];
	p[0] = new int[10];
	p[1] = new int[20];
	memset(p[0], 0, 20 * 4);
	memset(p[1], 0, 20 * 4);

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 20; ++j) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}