#include<iostream>
#include<string>
using namespace std;

class Pet {
    string pname;
public:
    Pet(const string& name) : pname(name) {}
    virtual string name() const { return pname; }
    virtual string description() const {
        return "This is " + pname;
    }
};

class Dog: public Pet {
    string favourite;
public:
    Dog(const string& name, const string& activity): Pet(name), favourite(activity) {}
    string description() const {
        return Pet::name() + " likes to " + favourite;
    }
};

void describe(Pet p) { // slicing, pass by value
    cout << p.description() << endl;
}

// when passing by value, the cc for a Pet object is used, thus initialize
// the VPTR to the Pet VTABLE

// if there is a pure virtual method in the base class, the compiler would prevent
// object slicing and generate an error
int main() {
    Pet p("Alfred");
    Dog d("Fluffy", "sleep");
    describe(p);
    describe(d);
}
