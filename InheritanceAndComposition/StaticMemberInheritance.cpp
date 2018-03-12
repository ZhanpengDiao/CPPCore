// static member act the same as non-static

#include<iostream>
using namespace std;

class Base {
public:
    static int i;
    void f() { cout << "Base::f() with " << i << endl; }
};

int Base::i = 10;

class Derived : public Base {
public:
    static int i;
};

int Derived::i = 100;

int main() {
    Derived d;
    d.f();
}
