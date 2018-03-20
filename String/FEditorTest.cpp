// test FileEditor
#include "FileEditor.h"
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    FileEditor file(argv[1]);
    int i = 1;
    FileEditor::iterator w = file.begin();
    while(w != file.end()) {
        ostringstream ss;
        ss << i++;
        *w = ss.str() + " " + *w;
        w++;
    }
    file.write();
}
