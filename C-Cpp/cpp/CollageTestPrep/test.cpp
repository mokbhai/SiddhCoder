#include <iostream>

class MyClass {
public:
    // Static data member
    static int staticData;

    // Regular data member
    int regularData;

    // Constructor
    MyClass(int regularDataValue) : regularData(regularDataValue) {}

    // Static member function
    static void staticFunction() {
        std::cout << "Static function called." << std::endl << staticData << std::endl;
        // Uncommenting the line below would result in a compilation error
        // std::cout << regularData << std::endl;  // Error!
    }

    // Regular member function
    void regularFunction() {
        std::cout << "Regular function called." << std::endl;
        std::cout << "Regular data: " << regularData << std::endl;
    }
};

// // Definition of the static data member
int MyClass::staticData = 0;

int main() {
    // Accessing static data member
    MyClass::staticData = 42;

    // Accessing static member function
    MyClass::staticFunction();

    // Creating instances of the class
    MyClass obj1(10);
    MyClass obj2(20);

    // Accessing regular member function
    obj1.regularFunction();
    obj2.regularFunction();

    return 0;
}
