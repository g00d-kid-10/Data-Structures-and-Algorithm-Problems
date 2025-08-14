#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    int costCalculator(int i, int j, string& s1, string& s2) {
        if(i < 0 && j < 0) {
            return 0;
        }

        if(i < 0) {
            int cost = 0, it1 = j;
            while(it1 > 0) cost += s2[it1--];
            return cost;
        }

        if(j < 0) {
            int cost = 0, it2 = i;
            while(it2 > 0) cost += s1[it2--];
            return cost;
        }

        cout<<i<<" "<<j<<"*";

        int cost = 0;
        if(s1[i] != s2[j]) {
            int x = s1[i] + costCalculator(i - 1, j, s1, s2);
            int y = s2[j] + costCalculator(i, j - 1, s1, s2);
            int z = s1[i] + s2[j] + costCalculator(i - 1, j - 1, s1, s2);
            cost = min({x, y, z});
        } else {
            cost = costCalculator(i - 1, j - 1, s1, s2);
        }

        return cost;
    }

    int minimumDeleteSum(string s1, string s2) {
        return costCalculator(s1.length() - 1, s2.length() - 1, s1, s2);
    }
};

int main() {
    Solution s;
    string s1 = "delete";
    string s2 = "leet";
    s.minimumDeleteSum(s1, s2);
    return 0;
}