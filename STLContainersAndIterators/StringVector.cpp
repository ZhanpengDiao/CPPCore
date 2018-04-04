// a vector of strings
// holding obj instead of operators
// cannot use polymorphism, or sliced

#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<iterator>
#include<sstream>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream in(argv[1]);
    vector<string> strings;
    string line;
    while(getline(in, line)) {
        strings.push_back(line);
    }

    int i = 1;
    vector<string>::iterator w;
    for(w = strings.begin(); w != strings.end(); w++) {
        ostringstream ss; // easy conversion from int to string
        ss << i++;
        *w = ss.str() + " " + *w;
    }

    // send cout
    copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));
}
