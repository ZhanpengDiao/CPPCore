#include "UsingDeclaration.h"

void h() {
    using namespace U; // using directive
    using V::f; // using UsingDeclaration
    f(); // call V::f()
    U::f(); // must fully quailify to call
}

int main() {}
