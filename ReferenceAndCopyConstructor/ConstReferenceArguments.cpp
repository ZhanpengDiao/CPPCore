// passing reference as const
// such as returned value by functions

void f(int&) {}
void g(const int&) {}

int main() {
    // f(1); // error: because the compile must allocate storage for an int and
    // initialize the reference, which is const.
    g(1);
}
