// local overload new & delete

#include<cstddef>
#include<fstream>
#include<iostream>
#include<new>
using namespace std;
ofstream out("S.out");

class S{
    enum { sz = 10 };
    char c[sz]; // to take up space, not used
    static unsigned char pool[]; // STORAGE used to hold all S
    static bool alloc_map[]; // STORAGE used to check if a position has been taken
public:
    enum { psize = 100 };
    S() { out << "S()" << endl; }
    ~S() { out << "~S()" << endl; }
    void* operator new(size_t) throw(bad_alloc);
    void operator delete(void*);
};

unsigned char S::pool[psize * sizeof(S)];
bool S::alloc_map[psize] = {false};

void* S::operator new(size_t) throw(bad_alloc) {
    for(int i = 0; i < psize; i ++) {
        if(!alloc_map[i])  // find an empty space
            out << "using block " << i << " ... ";
            alloc_map[i] = true;
            return (pool + i * sizeof(S)); // initial position,
        }
    }
    throw bad_alloc();
}

void S::operator delete(void* m) {
    if(!m) return;
    // ASSUME it was created in pool
    // calculate which block member it is
    unsigned long block = (unsigned long)m - (unsigned long)pool;
    block /= sizeof(S);
    out << "freeing block " << block << endl;
    // make it free
    alloc_map[block] = false;
}

int main() {
    S* f[S::psize];
    try {
        for(int i = 0; i < S::psize; i ++) f[i] = new S;
        new S; // out of memory
    } catch(bad_alloc) {
        cerr << "out of memory" << endl;
    }
    delete f[10];
    f[10] = 0;
    // use released memory
    S* s = new S;
    delete s;
    for(int j = 0; j < S::psize; j ++) {
        delete f[j];
    }
}
