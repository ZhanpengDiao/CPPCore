// Find a group of characters in a string
#include<iostream>
#include<string>
using namespace std;

// Case insensitive comparsion
int stringCompi(const string& s1, const string& s2) {
    string::const_iterator p1 = s1.begin(), p2 = s2.begin();

    while(p1 != s1.end() && p2 != s2.end()) {
        // only compare upper-cased chars:
        if(toupper(*p1) != toupper(*p2))
            return (toupper(*p1) < toupper(*p2)) ? -1 : 1;
        p1++;
        p2++;
    }

    return (s2.size() - s1.size());
}

int main() {
    string s1("Mozart");
    string s2("Modigliani");
    cout << stringCompi(s1, s2) << endl;
}
