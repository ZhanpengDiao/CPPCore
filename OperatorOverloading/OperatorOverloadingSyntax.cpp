
#include<iostream>
using namespace std;

class Integer {
    int i;
public:
    Integer(int i): i(i) {}

    const Integer operator+ (const Integer& o) const {
        cout << "operator+" << endl;
        return Integer(i + o.i);
    }

    Integer& operator+= (const Integer& o) {
        cout << "operator+=" << endl;
        i += o.i;
        return *this;
    }
};

int main() {
    cout << "built-in types: " << endl;
    int i = 1, j = 2, k = 3;
    k += i + j;
    cout << "user-defined types: " << endl;
    Integer ii(1), ij(2), ik(3);
    ik += ii + ij; 
}
