// print a string in reverse
#include<string>
#include<iostream>
using namespace std;

int main() {
    string s("987654321");
    string::reverse_iterator rev;
    for(rev = s.rbegin(); rev != s.rend(); rev++) { // not rev--
        cout << *rev << " ";
    }
}
