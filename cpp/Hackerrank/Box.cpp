#include<iostream>

using namespace std;
class Box {
    
    private:
    int l, b, h;
    
    public:
    
    Box() {
        l=0; b=0; h=0;
    }

    Box(int length,int breadth,int height) {
        l=length; b=breadth; h=height;
    }
    
    Box(Box &A) {
        A.l=l; A.b=b; A.h=h;
    }

    int getLength() {
        return l;
    }

    int getBreadth() {
        return b;
    }

    int getHeight() {
        return h;
    }

    long long CalculateVolume() {
        return l*b*h;
    }

    bool operator < (Box &B) {
        
        Box A(getLength(),getBreadth(),getHeight());

            if(A.l<B.l||A.b<B.b&&A.l==B.l||A.h<B.h&&A.b==B.b&&A.l==B.l) {
                return true;
            }
            else {
                return false;
            }
    }

    friend ostream& operator<<(ostream& os, Box& B);
};

ostream& operator<<(ostream& os, Box& B) {
    os<<B.l<<" "<<B.b<<" "<<B.h;
    return os;
}

int main() {

    Box b1(100,100,99);
    Box b2(1000,999,856);
    bool x = (b1 < b2);
    cout<<"\n";
    if(x)
    {cout<<"true";}
    else
    {cout<<"false";}
    cout<<b2;

    return 0;
}