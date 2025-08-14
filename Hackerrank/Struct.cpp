#include <iostream>
#include <string>
using namespace std;

struct Student {
    int age;
    string first_name;
    string last_name;
    int stand;
};

int main() {
    Student one;
    cin>>one.age>>one.first_name>>one.last_name>>one.stand;
    cout<<one.age<<" "<<one.first_name<<" "<<one.last_name<<" "<<one.stand;
    return 0;
}