#include <iostream>
using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int temp = purchaseAmount % 10;
        int roundedAmount = (temp < 5) ? purchaseAmount - temp : purchaseAmount + (10 - temp);
        return 100 - roundedAmount;
    }
};


int main() {
    Solution s;
    int x;
    cin>>x;
    cout<<s.accountBalanceAfterPurchase(x);
    return 0;
}