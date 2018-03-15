// navigation class hierarchies with static_cast
#include<iostream>
#include<typeinfo>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
};
class Circle: public Shape {};
class Square: public Shape {};
class Other {};

int main() {
    Circle c;
    Shape* s = &c; // upcast
    s = static_cast<Shape*>(&c); // explicit static cast, but unnecessary

    Circle* cp = 0;
    Square* sp = 0;
    // Static navigation of class hierarchies
    // require extra type information
    if(typeid(s) == typeid(cp)) // C++ RTTI
        cp = static_cast<Circle*>(s); // so it means the type id of s and cp is different
    if(typeid(s) == typeid(sp))
        sp = static_cast<Square*>(s);
    if(cp != 0) cout << "it is a circle" << endl;
    if(sp != 0) cout << "it is a square" << endl;

    // dynamic_cast is always safer, but have a bit overhead
    // Other* op = static_cast<Other*>(s) gives an error, but
    Other* op = dynamic_cast<Other*>(s);
    op = (Other*)s;
    // does not
}
