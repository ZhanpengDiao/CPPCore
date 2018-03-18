#include<iostream>
#include<string>
using namespace std;

int main() {
    string news("I saw Elvis in a UFO.");
    cout << news << endl;

    // get size of data
    cout << "Size = " << news.size() << endl;

    // how much data can store without allocating
    cout << "Capacity = " << news.capacity() << endl;

    // Insert a string
    news.insert(1, " thought I");
    cout << news << endl;
    cout << "Size = " << news.size() << endl;
    cout << "Capacity = " << news.capacity() << endl;

    // make sure there will be more spaces
    news.reserve(500);

    // add to the end
    news.append("I've been working too hard.");
    cout << news << endl;
    cout << "Size = " << news.size() << endl;
    cout << "Capacity = " << news.capacity() << endl;

}
