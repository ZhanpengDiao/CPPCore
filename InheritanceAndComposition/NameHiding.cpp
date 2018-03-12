// Hiding overloaded names during inheritance
// Refining and Overloading

#include<iostream>
#include<string>
using namespace std;

class Base {
public:
    int f() const {
        cout << "Base::f()\n";
        return 1;
    }
    int f(string) const {return 1;}
    void g() {}
};

class Derive1: public Base {
public:
    void g() const {}
};

class Derive2: public Base {
public:
    // Redefinition:
    int f() const {
        cout << "Derived2::f()\n";
        return 2;
    }
};

class Derive3: public Base {
public:
    // Change return type
    void f() const { cout << "Derived3::f()\n"; }
};

class Derive4: public Base {
public:
    // Change argument list
    int f(int) const {
        cout << "Derived4:f()\n";
        return 4;
    }
};

int main() {
    string s("hello");

    Derive1 d1;
    int x = d1.f();
    d1.f(s);

    Derive2 d2;
    x = d2.f();
    // d2.f(s); // string version hidden

    Derive3 d3;
    // x = d3.f(); // return int version hidden

    Derive4 d4;
    // x = d4.f(); // f() version hidden
    x = d4.f(1);
}
