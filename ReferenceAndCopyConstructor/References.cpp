// a reference must be initialized when created
// (must be tied to specific piece of memory)
// once a reference is initialized to a object, it cannot change
// cannot have NULL reference

// Simple reference practice

// when a reference is created, it must be initialized to a live object
// however, below means the compile allocate a piece of storage and ties the reference
const int& q = 12;

int* f(int* x) {
    (*x)++;
    return x; // safe, x is outside the scope
}

int& g(int& x) {
    x++;
    return x; // safe, x is outside the scope
}

int& h() {
    // const int i = 0; // error, doesn't live outside the scope
    static int i; // obj of reference must keep alive
    return i;
}

int main() {
    int a = 0;
    f(&a); // explicit style
    g(a); // clean style
}
