// simple find-and-replace
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s("a piece of text");
    string tag("$tag$");
    s.insert(8, tag + ' ');
    cout << s << endl;
    int start = s.find(tag);
    cout << "start = " << start << endl;
    cout << "size = " << tag.size() << endl;
    s.replace(start, tag.size(), "hello there");
    cout << s << endl;
}
