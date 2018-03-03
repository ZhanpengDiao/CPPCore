// define and use a pointer to a function

#include <iostream>
using namespace std;

void func() {
    cout << "func() is called" << endl;
}

int main() {
    void (*fp)();
    fp = func;
    (fp)(); // taking the address of dereferencing a function just evaluate to a pointer of that function
    // which equals (*fp)();
}
