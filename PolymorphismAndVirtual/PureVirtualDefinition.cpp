// pure virtual base definition
#include<iostream>
using namespace std;

class Pet {
public:
    virtual void speak() const;
    virtual void eat() const = 0; // keep the VTABLE incomplete
    // inline pure virtual definition is illegal
    // virtual void sleep() const = 0 {}
};

// it is ok to define outside
void Pet::eat() const {
    cout << "Pet::eat()" << endl;
}

void Pet::speak() const {
    cout << "Pet::speak()" << endl;
}

class Dog: public Pet {
public:
    // use common pet code
    // void speak() { Pet::speak(); } // if it is not pure, do not need to declare again
    void eat() const { Pet::eat(); } // if it is pure, need to re-declare
};

int main() {
    Dog simba;
    simba.eat();
    simba.speak();
}
