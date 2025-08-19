#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int age, standard;
        string first_name, last_name;
    public:
        void get_age(int a) {
            age=a;
        }
        
        void get_standard(int sta) {
            standard=sta;
        }
        
        void get_first_name(string first) {
            first_name=first;
        }
        
        void get_last_name(string last) {
            last_name=last;
        }

        int set_age() {
            return age;
        }
        
        int set_standard() {
            return standard;
        }
        
        string set_first_name() {
            return first_name;
        }
        
        string set_last_name() {
            return last_name;
        }

        string myto_string() {
            return to_string(age)+","+first_name+","+last_name+","+to_string(standard);
        }
};

int main() {
    Student s;
    int age, standard;
    string first, last;
    cin>>age>>first>>last>>standard;
    s.get_age(age);
    s.get_first_name(first);
    s.get_last_name(last);
    s.get_standard(standard);
    cout<<s.set_age()<<endl;
    cout<<s.set_last_name()<<", "<<s.set_first_name()<<endl;
    cout<<s.set_standard()<<endl;
    cout<<endl;
    cout<<s.myto_string();
    return 0;
}