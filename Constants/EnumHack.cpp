// enum evaluated at compile time
// local to class
// replaceable with static const

#include<iostream>
using namespace std;

class Bunch {
    enum { size = 100 };
    int i[size];
    // below will not work since const is not evaluated at compile time
    // const int sz = 100;
    // int i[sz];
};

int main() {
    cout << "sizeof(Bunch) = " << sizeof(Bunch) <<
    ", sizeof(int[1000]) = " << sizeof(int[100]) << endl;
}
