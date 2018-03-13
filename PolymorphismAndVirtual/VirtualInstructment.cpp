// Late binding with the virtual keyword
#include<iostream>
using namespace std;
enum note {middleC, Csharp, Cflat};

class Instrument {
public:
    virtual void play(note) const { // virtual triggers late binding
        cout << "Instrument::play" << endl;
    }
};

class Wind: public Instrument {
    // Override
    void play(note) const {
        cout << "Wind::play" << endl;
    }
};

void tune(Instrument& i) {
    i.play(middleC);
}

int main() {
    Wind flute;
    tune(flute);
}
