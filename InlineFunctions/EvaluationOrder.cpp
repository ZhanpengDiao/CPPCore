// inline evaluation order
// an inline makes a forward reference to a function
// within a class

class Forward {
    int i;
public:
    Forward() : i(0) {}
    // call to undeclared function
    int f() const { return g() + 1; } // because g() is an inline included in the class
    int g() const { return i; }
};

int main() {
    Forward f;
    f.f();
}
