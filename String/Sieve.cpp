#include<string>
#include<iostream>
using namespace std;

int main() {
    // create 50 char string with each elem set to 'P'
    // 'P' is Prime
    string sieveChars(50, 'P');
    // change to 'N' for Not Prime
    sieveChars.replace(0, 2, "NN");
    for(int i = 2; i <= (sieveChars.size() / 2) - 1; i ++) {
        // find all factors
        for(int factor = 2; factor * i < sieveChars.size(); factor ++) {
            sieveChars[factor * i] = 'N'; // replace char
        }
    }
    cout << sieveChars << endl;

    cout << "Prime:" << endl;
    // find the first Prime
    int j = sieveChars.find('P');
    while(j != string::npos) {
        cout << j << " ";
        j++;
        j = sieveChars.find('P', j);
    }
    cout << endl;

    cout << "Not Prime:" << endl;
    // find the first Prime
    j = sieveChars.find_first_not_of('P');
    while(j != string::npos) {
        cout << j << " ";
        j++;
        j = sieveChars.find_first_not_of('P', j);
    }
}
