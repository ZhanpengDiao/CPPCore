// Temporaries are const

class X {};

X f() { return X(); } // return by value

void g1(X&) {} // pass by non-const reference
void g2(const X&) {} // pass by const reference

int main() {
    // g1(f()); //! error : const temporary created by f()
    g2(f());
}
