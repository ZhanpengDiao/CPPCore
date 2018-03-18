#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    string a("aaaXaaaXXaaXXXaXXXXaaa");
    cout << a << endl;
    replace(a.begin(), a.end(), 'X', 'Y'); // use STL algo
    cout << a << endl;
}
