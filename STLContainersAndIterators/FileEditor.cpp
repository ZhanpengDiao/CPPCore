#include "FileEditor.h"
#include <fstream>
using namespace std;

FileEditor::FileEditor(char* fName) {
    ifstream in(fName);
    string line;
    while(getline(in, line)) {
        push_back(line);
    }
}

void FileEditor::write(ostream& out) {
    for(iterator w = begin(); w != end(); w++) { // note the declaration of w
        out << *w << endl;
    }
}
