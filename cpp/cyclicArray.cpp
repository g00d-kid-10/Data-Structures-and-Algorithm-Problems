#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 5, 7, 3, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 3;
    int k = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++, k++) {
            cout<<arr[k%size];
        }
        cout<<endl;
    }
    return 0;
}