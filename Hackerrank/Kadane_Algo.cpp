#include <bits/stdc++.h>
using namespace std;

int main() {
    int max_so_far=INT_MIN;
    int sum=0;
    int arr[8] = {-5, -3, -4, -1, -2, -1, -1, 0};
    
    for(int i=0;i<8;i++) {
        sum=sum+arr[i];
        if(sum > max_so_far) {
            max_so_far = sum;            
        }
        if(sum<0) {
            sum=0;
        }
    }

    cout<<max_so_far;
    return 0;

}