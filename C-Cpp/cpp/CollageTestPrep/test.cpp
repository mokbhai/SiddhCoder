#include <iostream>
using namespace std;

class Fruit {
public:
    virtual void printColor() const {
        cout << "Unknown color" << endl;
    }
};

class Banana : public Fruit {
public:
    void printColor() const override {
        cout << "Yellow" << endl;
    }
};

int main() {
    Fruit* f = new Banana;
    f->printColor();
    delete f;
    return 0;
}