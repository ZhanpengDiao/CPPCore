// Pointer Stash definition

#include "PStash.h"
#include<iostream>
#include<cstring>
using namespace std;

int PStash::add(void* element) {
    const int inflateSize = 10;
    if(next >= quantity) { inflate(inflateSize); }
    storage[next++] = element;
    return (next - 1); // return the element position
}

PStash::~PStash() {
    for(int i = 0; i < next; i ++) {
            if(storage[i] != 0) cout << "PStash not cleaned up" << endl;
    }
    delete[] storage;
}

// Operator overloading for fetching
void* PStash::operator[](int index) const{
    if(index >= next) { return 0; } // indicate the end
    return storage[index];
}

void* PStash::remove(int index) { // when deletion: delete (string*)aStash.remove(k);
    void* v = operator[](index); // is this clause = storage[index] ?
    if(v != 0) storage[index] = 0;
    return v;
}

void PStash::inflate(int increase) {
    const int vpsz = sizeof(void*);
    void** nst = new void*[quantity + increase];
    memset(nst, 0, (quantity + increase) * vpsz);
    memcpy(nst, storage, quantity * vpsz);
    quantity += increase;
    delete[] storage;
    storage = nst;
}
