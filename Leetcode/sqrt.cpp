#include <iostream>
#include <math.h>
using namespace std;


int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        
        int l=0, u=x/2, m;
        while(l<=u) {
            m=l+(u-l)/2;
            if(m == x/m){
                return m;    
            }  else if(m < x/m) {
                l=m+1;
            } else {
                u=m-1;
            }
            cout<<endl;
        }
        return (l<u) ? l : u;
    }

int main() {
    cout<<mySqrt(14);
    return 0;
}