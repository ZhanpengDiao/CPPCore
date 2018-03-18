#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1
        ("What is the sound of one clam napping?");
    string s2
        ("Anything worth doing is worth overdoing.");
    string s3
        ("I saw Elvis in a UFO.");

    // copy the first 8 chars
    string s4(s1, 0, 8);
    // copy 6 chars from the middle
    string s5(s2, 15, 6);
    // copy from middle to the end
    string s6(s3, 6, 15);

    // copy all
    string quoteMe = s4 + "that" +
    // substr() copies 10 chars at element 20
    s1.substr(20, 10) + s5 +
    // substr() copies either 100 chars of eos starting at element 5
    "with" + s3.substr(5, 100) +
    // copy a single char
    s1.substr(37, 1);
    cout << quoteMe << endl;
    cout << string(s1.begin(), s1.end()) << endl;
}
