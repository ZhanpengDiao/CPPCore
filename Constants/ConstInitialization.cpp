// Initializing const in class
// constructor initializer list
// originally designed for inheritance
// the list initialization occurs before the main constructor body

// "const" behaves differently inside a class

#include<iostream>
using namespace std;

class Fred {
    const int size;
public:
    Fred(int sz);
    void print();
};

Fred::Fred(int sz) : size(sz) {}
void Fred::print() { cout << size << endl; }

int main() {
    Fred a(1), b(2), c(3);
    a.print(), b.print(), c.print(); // en...I can call functions like this
}
