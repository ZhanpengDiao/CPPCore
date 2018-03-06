// fragile base-class problem:
// change to a file can cause recomilpation
// of this file and another files dependent upon

// solution: handle classes (Cheshire cat)
// everything about the implementation disappears
// except for a single pointer

#ifndef HANDLE_H
#define HANDLE_H

class Handle {
    struct Cheshire; // class declaration only
    Cheshire* smile;
public:
    void initialize();
    void cleanup();
    int read();
    void change(int);
};

#endif // HANDLE_H
