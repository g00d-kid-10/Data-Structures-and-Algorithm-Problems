#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), k=0;
        for(int i=0; i<n-1; i++) {
            if(nums[i]==nums[i+1]) nums[i] = 101; else k++;
        }
        sort(nums.begin(), nums.end());
        return k+1;
    }
};

using namespace std;
int main() {
    Solution s;
    vector<int> v = {0, 0, 2, 2, 2, 4, 5};
    vector<int>::iterator itr;

    int k = s.removeDuplicates(v);
    
    cout<<k<<endl;
    for(auto x : v)
        cout<<x<<" ";
    return 0;
}