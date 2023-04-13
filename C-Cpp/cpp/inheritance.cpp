#include <iostream>
using namespace std;
class Vehicle {
  public:
    void forw(){
        cout << "Forword..\n";
    }
    void horn() {
      cout << "Pooo!\n" ;
    }
    void breaks(){
        cout << "Breaks!!\n";
    }
};

// Derived class
class Car: public Vehicle {
    string name = "BMW\n";
    int whells = 4;
};
class bike: public Vehicle {
    string name = "Bullet\n";
    int whells = 2;
};

int main() {
  Car myCar;
  bike mybike;
//   cout << name;
  myCar.horn();
  myCar.forw();
  myCar.breaks();
  cout << "Bike\n";
  mybike.horn();
  mybike.forw();
  mybike.breaks();
  return 0;
}