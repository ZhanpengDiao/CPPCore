// built in types as template arguments
#include<iostream>
using namespace std;

// bulit-in types become compile time constants
template<class T, int size = 100>
class Array {
    T array[size];
public:
    T& operator[] (int idx) {
        if(idx < 0 || idx > size) {
            cout << "Index out of range" <<  endl;
            exit(1);
        }
        return array[idx];
    }
    int length() const { return size; }
};

class Number {
    float f;
public:
    Number(float f = 0.0f): f(f) {}
    Number& operator= (const Number& n) {
        f = n.f;
        return *this;
    }
    operator float() const { return f; }
    friend ostream& operator<< (ostream& os, const Number& n) {
        return os << n.f;
    }
};

template<class T, int size = 20>
class Holder {
    Array<T, size>* np;
public:
    Holder(): np(0) {}
    T& operator[](int idx) {
        if(!np) np = new Array<T, size>; // lazy initialization
        return np->operator[](idx);
    }
    int length() const { return size; }
    ~Holder() { delete np; }
};

int main() {
    Holder<Number> h;
    for(int i = 0; i < 20; i ++) {
        h[i] = i;
    }
    for(int j = 0; j < 20; j ++) {
        cout << h[j] << endl;
    }
}
