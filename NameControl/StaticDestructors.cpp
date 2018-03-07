// static object destructor

#include<fstream>
using namespace std;
ofstream out("statdest.out"); // trace file

class Obj {
    char c;
public:
    Obj(char c): c(c) {
        out << "Obj::Obj() for " << c << endl;
    }

    ~Obj() {
        out << "Obj::~Obj() for " << c << endl;
    }
};

Obj a('a'); // Global // staic storage
// constrctor & destructor always called
// called be for main() is entered

void f() {
    static Obj b('b');
}

void g() {
    static Obj c('c');
}

int main() {
    out << "inside main()" << endl;
    f(); // call static constrctor for b
    out << "leaving main()" << endl;
}
