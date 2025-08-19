#include <iostream>
#include <string>
using namespace std;

class Complex
{
    private:
    int a,b;
    int i=0,temp1=0,temp2=0;
    int c,d;

    public:
    void input(string s)
    {
        while(s[i]!='+')
        {
            temp1=temp1*10+s[i]-'0';
            i++;
        }
        
        while(s[i]==' '||s[i]=='i'||s[i]=='+')
        {
            i++;
        }

        while(i<s.length())
        {
            temp2=temp2*10+s[i]-'0';
            i++;
        }
        
        a=temp1;
        b=temp2;
    }
    
    Complex operator+(Complex const& obj1)
    {
        Complex newo1;
        newo1.a=a+obj1.a;
        newo1.b=b+obj1.b;
        return newo1;
    }

    friend ostream& operator<<(ostream& os, const Complex& newo1);
};

ostream& operator<<(ostream& os, const Complex& newo1)
    {
        os<<newo1.a<<"+i"<<newo1.b;
        return os;
    }

int main()
{
    Complex o1,o2;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    o1.input(s1);
    o2.input(s2);
    Complex o=o1+o2;
    cout<<o<<endl;
}
