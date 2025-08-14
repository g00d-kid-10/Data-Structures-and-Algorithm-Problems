#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {2, 7, 1, 4};
    int k = 7, n = numbers.size();
    int count = 0, curr = 1;
    for(int i = 0, j = 0; j < n; j++) {
        curr *= numbers[j];
        while(i <= j && curr > k) {
            curr /= numbers[i];
            i++;
        }
        count += (j - i + 1);
    }

    cout << count;
    
    return 0;
}
























