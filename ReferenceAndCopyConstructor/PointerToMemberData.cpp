#include<iostream>
using namespace std;

class Data {
public:
    int a, b, c;
    void print() const {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

int main() {
    Data d, *dp = &d;
    int Data::*pmInt = &Data::a; //referring to class, not the obj of the class
    // for better understand, it looks like: *pmInt = &a
    dp->*pmInt = 37;
    pmInt = &Data::b;
    d.*pmInt = 38;
    pmInt = &Data::c;
    dp->*pmInt = 39;
    dp -> print();
}
