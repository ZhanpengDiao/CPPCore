#include<iostream>
#include<string>
using namespace std;

void replaceChars(string& modifyMe, string findMe, string newChars) {
    // look in modifyMe for the findMe starting at position 0
    int i = modifyMe.find(findMe, 0); // starting at 0
    if(i != string::npos) { // until the end of the string
        // replace the find string with new newChars
        modifyMe.replace(i, newChars.size(), newChars);
    }
}

int main() {
    string news =
        "I thought I saw Elvis in a UFO."
        "I have been working too hard.";
    string s = "wig";
    string findMe = "UFO";
    replaceChars(news, findMe, s);
    cout << news << endl;
}
