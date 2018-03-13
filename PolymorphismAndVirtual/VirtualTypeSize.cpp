// Object sizes with/without virtual functions
#include<iostream>
using namespace std;

class NoVirtual {
    int a;
public:
    void x() const {}
    int i() const { return 1; }
};

class OneVirtual {
    int a;
public:
    virtual void x() const {}
    int i() const { return 1; }
};

class TwoVirtual {
    int a;
    virtual void x() const {}
    virtual i() const { return 1; }
};

int main() {
    cout << "int: " << sizeof(int) << endl;
    cout << "NoVirtual: " << sizeof(NoVirtual) << endl;
    cout << "OneVirtual: " << sizeof(OneVirtual) << endl;
    cout << "TwoVirtual: " << sizeof(TwoVirtual) << endl;
}
