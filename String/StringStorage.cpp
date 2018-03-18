#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1("12345");
    string::iterator it = s1.begin(); // indicate the first element

    // this may copy s1 to s2 or
    // use REFERENCE COUNTING to simulate a copy
    string s2 = s1;
    // however the statment only modify s1
    *it = '0';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
}
