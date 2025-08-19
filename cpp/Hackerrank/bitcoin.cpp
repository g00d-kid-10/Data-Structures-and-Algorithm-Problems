#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    private:
    int n, m, k, max;
    vector<int> conv_rate;
    vector<int> curr_count;

    public:
    Solution() : n(0), m(0), k(0), max(0) {
        
        cin>>n>>m>>k;
        max = m*k;
        
        for(int i=0; i<n; i++) {
            int temp = 0;
            cin>>temp;
            conv_rate.push_back(temp);    
        }
        
        for(int i=0; i<n; i++) {
            int temp = 0;
            cin>>temp;
            curr_count.push_back(temp);
        }
    }
    
    int max_doll() {
        for(int i=0; i<n; i++) {
            int temp = m*curr_count[i]*conv_rate[i];
            max = (max>temp) ? max : temp;
        }
        return max;
    }
};

int main() {
    Solution s;
    cout<<s.max_doll();
}
