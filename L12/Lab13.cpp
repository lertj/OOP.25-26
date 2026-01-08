#include <iostream>

using namespace std;

int add(float x, int y) { // function that is overloaded
    return x + y;
}

float add(int x, int y) { // overload
    return x + y;
}

float add(int x, int y, int z) { // overload
    return x + y + z;
}

class Animal {
protected:
    std::string name;
    float weight;

public:

    Animal(string name, float weight) {
        this->name = name;
        this->weight = weight;
    }

    void printInfo() {
        cout << "Name: " << this->name << endl;
        cout << "Weight: " << this->weight << endl;
    }
};

class Mammal : public Animal { // is a
    int milkVolume = 0;

public:
    Mammal() : Animal("-",0) {

    }

    Mammal(string name, float weight, int milkVolume) : Animal(name, weight) {
        this->milkVolume = milkVolume;
    }

    void printInfo() {
        this->Animal::printInfo();
        cout << "Milk volume: " << this->milkVolume << endl;
    }

};

int main()
{
   Animal duck = Animal("duck", 3.5f);
   duck.printInfo();
   Mammal cat = Mammal("cat", 1.25f, 1);
   cat.printInfo();

   Animal lion = cat; //upcast
   lion.printInfo();

   Mammal dog = duck;

   int x= add(5, 6);
}
