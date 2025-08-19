#include <iostream>
#include <vector>

using namespace std;
int main() {
	vector<int> nums = {2, 1, 2, 3, 2, 5, 2, 6, 2, 2, 6, 7, 9};
	int i = 0, j = 0;
	while(j < nums.size()) {
		if(nums[j] != 2) {
			swap(nums[i], nums[j]);
			i++;
		}
		j++;
	}

	for(auto x : nums) cout << x << " ";
	return 0;
}