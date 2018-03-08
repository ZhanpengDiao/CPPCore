// if you do not need pass-by-value, don't need to create cc

// technique to prevent pass-by-value

class NoCC {
    int i;
    NoCC(const NoCC&) {} // private cc, prevent pass-by-value
public:
    NoCC(int i = 0) : i(i) {}
};

void f(NoCC n) {};

int main() {
    NoCC n;
    // f(n); // error: cc is called
    // NoCC n2 = n;
    // NoCC n3(n);
}
