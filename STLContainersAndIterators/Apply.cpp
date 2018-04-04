// template to work with container

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<class Cont, class PtrMemFun>
void apply(Cont& c, PtrMemFun f) {
        typename Cont::iterator it = c.begin();
        while(it != c.end()) {
            // (it->*f)(); // compact form // won't work, why?
            ((*it).*f)();
            it++;
        }
}

class Z {
    int i;
public:
    Z(int i): i(i) {}
    void g() { i++; }
    friend ostream& operator<< (ostream& os, const Z& z) {
        return os << z.i;
    }
};

int main(int argc, char* argv[]) {
    ostream_iterator<Z> out(cout, " ");
    vector<Z> v;
    for(int i = 0; i < 10; i ++) {
        v.push_back(Z(i));
    }
    copy(v.begin(), v.end(), out);
    cout << endl;
    apply(v, &Z::g);
    copy(v.begin(), v.end(), out);
}
