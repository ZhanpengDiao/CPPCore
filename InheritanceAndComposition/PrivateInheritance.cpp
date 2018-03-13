
// hide part of functions of base class

class Pet {
public:
    char eat() {return 'a';}
    int speak() {return 1;}
    float sleep() const {return 2.0;}
    float sleep(int) const {return 4.0;}
};

class Goldfish: Pet { // DEFALUT private inheritance
public:
    using Pet::eat; // using new syntax ... en...
    using Pet::sleep; // all overloaded functions exposed
};

int main() {
    Goldfish bob;
    bob.eat();
    bob.sleep();
    // bob.speak(); // private functions
}
