// overload global new/delete

#include<cstdio>
#include<cstdlib>
using namespace std;

// new is called before constructor
void* operator new(size_t sz) { // old C type, the size of new object
    printf("Operator new: %d Bytes\n", sz); // don't use iostream because object is created by new
    void* m = malloc(sz);
    if(!m) puts("out of memory"); // no enough left
    return m;
}

// delete is called after destructor
void operator delete(void* m) {
    puts("operator delete");
    free(m);
}

class S {
    int i[100];
public:
    S() { puts("S::S()"); }
    ~S() { puts("S::~S()"); }
};

int main() {
    puts("creating and destorying an int");
    int* p = new int();
    delete p;
    puts("creating and destorying an S");
    S* s = new S();
    delete s;
    puts("creating and destorying an S[3]");
    S* sa = new S[3];
    delete []sa; // if use detele[] sa, only the first item is destoryed
}
