// Union can have constructors and member functions

#include<iostream>
using namespace std;

union U {
private:
    int i;
    float f;
public:
    U(int i);
    U(float f);
    ~U();
    int read_int();
    float read_float();
};

U::U(int i) {
    this -> i = i;
}

U::U(float f) {
    this -> f = f;
}

U::~U() {
    cout << "U::~U()" << endl;
}

int U::read_int() {
    return i;
}

float U::read_float() {
    return f;
}

int main() {
    U x(10), y(15.0f);
    cout << x.read_int() << endl; // this is not safe, e.g. x.read_float
    cout << y.read_float() << endl;
}
