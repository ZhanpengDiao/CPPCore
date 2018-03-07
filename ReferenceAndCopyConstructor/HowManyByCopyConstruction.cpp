
// a class that counts its object
//anomaly occurs

#include<iostream>
#include<string>
using namespace std;

class HowManyByCopyConstruction {
    static int CountObjects; // cannot initialized inside class
    string name; // object identifier
public:
    HowManyByCopyConstruction(const string& id = "") : name(id)
    { CountObjects++;print("HowManyByCopyConstruction()"); } // add one for each initialization

    // the new copy constructor, arg h is the original obj
    HowManyByCopyConstruction(const HowManyByCopyConstruction& h) : name(h.name) {
        name += "copy";
        ++CountObjects;
        print("HowManyByCopyConstruction(const HowManyByCopyConstruction&)");
    }

    void print(const string& msg = " ") {
        if(msg.size() != 0) cout << msg << ": ";
        cout << "\t" << name << ": " << "CountObjects = " << CountObjects << endl;
    }

    ~HowManyByCopyConstruction() { CountObjects--;print("~HowManyByCopyConstruction()"); }
};

int HowManyByCopyConstruction::CountObjects = 0;

// PASS AND RETURN BY VALUE:
HowManyByCopyConstruction f(HowManyByCopyConstruction x) {
    x.print("x argument inside f()");
    cout << "returning from f()" << endl;
    return x;
}

int main() {
    HowManyByCopyConstruction h("h");
    cout << "entering f()" << endl;
    HowManyByCopyConstruction h2 = f(h);
    h2.print("h2 after call to f()");
    cout << "call f(), no return value" << endl;
    f(h);
    cout << "after call to f()" << endl;
}
