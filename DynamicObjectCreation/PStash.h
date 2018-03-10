// Holds pointers instead of objects

#ifndef PSTASH_H
#define PSTASH_H

class PStash {
    int quantity; // num of storage spaces
    int next; // next empty spaces
    // pointer storage
    void** storage;
    void inflate(int increase); // during the time storage is full
public:
    PStash() : quantity(0), storage(0), next(0) {}
    ~PStash();
    int add(void* element);
    void* operator[](int index) const; // Fetch: user must remember what types are stored
    // remove reference from this PSTASH
    void* remove(int index);
    // num of elems in Stash
    int count() const { return next; }
};
#endif // PSTASH_H
