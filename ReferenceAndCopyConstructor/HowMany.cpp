// a class that counts its object
//anomaly occurs

#include<iostream>
#include<string>
using namespace std;

class HowMany {
    static int CountObjects; // cannot initialized inside class
public:
    HowMany() { CountObjects++; } // add one for each initialization

    static void print(const string& msg = " ") {
        if(msg.size() != 0) cout << msg << ": ";
        cout << "CountObjects = " << CountObjects << endl;
    }

    ~HowMany() { CountObjects--;print("~HowMany()"); }
};

int HowMany::CountObjects = 0;

// PASS AND RETURN BY VALUE:
HowMany f(HowMany x) { // here provide a copy of x for f, using bitcopy, no constructor called
    x.print("x argument inside f()");
    return x;
}

int main() {
    HowMany h;
    HowMany::print("after construction of h");
    HowMany h2 = f(h); // the create of h2 provide another copy
    HowMany::print("after call to f()");
}
