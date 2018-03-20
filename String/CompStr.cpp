#include<string>
#include<iostream>
using namespace std;

int main() {
    string s1("This ");
    string s2("That ");
    string s3("That ");
    // Use the string inequality operators
    if(s2 == s3) {
        cout << "s2 is == s3" << endl;
    }
}
