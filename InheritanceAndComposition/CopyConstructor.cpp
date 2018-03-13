// correctly creating the copy constructor
#include<iostream>
using namespace std;

class Parent {
    int i;
public:
    Parent(int i) : i(i) {
        cout << "Parent(int)" << endl;
    }
    // cc
    Parent(const Parent& p): i(p.i) {
        cout << "Parent(const Parent&)" << endl;
    }
    Parent() : i(0) { cout << "Parent()" << endl; }
    friend ostream& operator<< (ostream& os, const Parent& p) {
        return os << "Parent: " << p.i << endl;
    }
};

class Member {
    int i;
public:
    Member(int i): i(i) {
        cout << "Member(int)" << endl;
    }
    // cc
    Member(const Member& m): i(m.i) {
        cout << "Member(const Member&)" << endl;
    }
    friend ostream& operator<< (ostream& os, const Member& m) {
        return os << "Member: " << m.i << endl;
    }
};

class Child: public Parent { // no cc
    int i;
    Member m;
public:
    Child(int i): Parent(i), i(i), m(i) { // cannot write like: i(i), m(i)
        cout << "Child(int)" << endl;
    }
    friend ostream& operator<< (ostream& os, const Child& c) {
        return os << (Parent&)c << c.m
        << "Child: " << c.i << endl;
    }
};

int main() {
    Child c(2);
    cout << "calling copy-constructor: " << endl;
    Child c2 = c; // calls construcor
    cout << "i in c2:" << c2 << endl;
}
