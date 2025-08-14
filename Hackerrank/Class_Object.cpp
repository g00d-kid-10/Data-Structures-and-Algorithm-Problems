#include <iostream>
using namespace std;

class Student {
    
    private:
    
        int marks[5];
    
    public:
        
        void input() {
            for (int i=0;i<5;i++) {
                cin>>marks[i];
            }
        }

        int calcTotalScore() {
            int sum=0;
            for(int i=0;i<5;i++) {
                sum=sum+marks[i];
            }
            return sum;
        }
};

int main() {
    
    Student s;
    
int n, count=0; cin>>n;
    s.input();
    int base=s.calcTotalScore();
    
    for(int i=0;i<n-1;i++) {
        s.input();
        if(s.calcTotalScore()>base) {
            count++;
        }
    }

    cout<<count;
    
    return 0;
}