#include <iostream>
#include <cstdio>

using namespace std;

class Animal {
public: 
    Animal() {
        cout << "Animal constructor" << endl;
    }
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }

    virtual void speak() {
        cout << "No sound" << endl;
    }
private:
};

class Dog : public Animal {
public:
    Dog() : Animal() {
        cout << "Dog constructor" << endl;
    }
    virtual ~Dog() {
        cout << "Dog destructor" << endl;
    }
    virtual void speak() {
        cout << "Bark" << endl;
    }
private:

};

int main() {
    Animal *a = new Animal();
    a->speak();
    printf("a is at %p\n", a);
    delete a;
    a = nullptr;
    printf("a is at %p\n", a);

    a = new Dog();
    a->speak();
    printf("a is at %p\n", a);
    delete a;
    a = nullptr;
    printf("a is at %p\n", a);

    return 0;
}