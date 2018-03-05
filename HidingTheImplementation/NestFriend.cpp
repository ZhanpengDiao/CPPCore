// Nested friends
#include<iostream>
#include<cstring>
using namespace std;
const int sz = 10;

struct Holder {
private:
    int a[sz]; // array of int
public:
    void initialize();
    struct Pointer;
    // friend Pointer; // works without this declaration?
    struct Pointer {
    private:
        Holder* h;
        int* p;
    public:
        void initialize(Holder* h);
        // Move around in the array
        void next();
        void previous();
        void top();
        void end();
        // Access value
        int read();
        void set(int i);
    };
};

void Holder::initialize() {
    memset(a, 0, sz * sizeof(int)); // assign specific value to a section of memory starting from an address
}

void Holder::Pointer::initialize(Holder* h) {
    this -> h = h;
    p = h -> a;
}

void Holder::Pointer::next() {
    if(p < &(h -> a[sz - 1])) p++;
}

void Holder::Pointer::previous() {
    if(p > &(h -> a[0])) p--;
}

void Holder::Pointer::top() {
    p = &(h -> a[0]);
}

void Holder::Pointer::end() {
    p = &(h -> a[sz - 1]);
}

int Holder::Pointer::read() {
    return *p;
}

void Holder::Pointer::set(int i) {
    *p = i;
}

int main() {
    Holder h;
    Holder::Pointer hp, hp2;

    h.initialize();
    hp.initialize(&h);
    hp2.initialize(&h);
    for(int i = 0; i < sz; i++) {
        hp.set(i);
        hp.next();
    }

    hp.top();
    hp2.end();
    for(int i = 0; i < sz; i++) {
        cout << "hp= " << hp.read()
        <<  ", hp2 = " << hp2.read() << endl;
        hp.next();
        hp2.previous();
    }
    return 0;
}
