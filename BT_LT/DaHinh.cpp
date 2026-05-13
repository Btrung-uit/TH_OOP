#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const {
        cout << "Animal phát ra âm thanh chung\n";
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Chó: Gâu gâu!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Mèo: Meo meo!\n";
    }
};

int main() {
    Animal* zoo[2];
    zoo[0] = new Dog();
    zoo[1] = new Cat();

    for (int i = 0; i < 2; i++) {
        zoo[i]->speak(); // đa hình: Dog/Cat tương ứng
    }

    for (int i = 0; i < 2; i++) {
        delete zoo[i];
        zoo[i] = nullptr;
    }

    return 0;
}