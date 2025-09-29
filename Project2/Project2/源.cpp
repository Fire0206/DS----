#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void Speak() = 0;
    virtual ~Animal() {}
};

class Tiger : public Animal {
private:
    string name;
    int age;
public:
    Tiger(string n, int a) : name(n), age(a) {}
    void Speak() override {
        cout << "Hello,I am " << name << ",AOOO." << endl;
    }
};

class Dog : public Animal {
private:
    string name;
    int age;
public:
    Dog(string n, int a) : name(n), age(a) {}
    void Speak() override {
        cout << "Hello,I am " << name << ",WangWang." << endl;
    }
};

class Duck : public Animal {
private:
    string name;
    int age;
public:
    Duck(string n, int a) : name(n), age(a) {}
    void Speak() override {
        cout << "Hello,I am " << name << ",GAGA." << endl;
    }
};

class Pig : public Animal {
private:
    string name;
    int age;
public:
    Pig(string n, int a) : name(n), age(a) {}
    void Speak() override {
        cout << "Hello,I am " << name << ",HENGHENG." << endl;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string animalName, name;
        int age;
        cin >> animalName >> name >> age;
        Animal* ptr = nullptr;
        if (animalName == "Tiger") {
            ptr = new Tiger(name, age);
        }
        else if (animalName == "Dog") {
            ptr = new Dog(name, age);
        }
        else if (animalName == "Duck") {
            ptr = new Duck(name, age);
        }
        else if (animalName == "Pig") {
            ptr = new Pig(name, age);
        }
        else {
            cout << "There is no " << animalName << " in our Zoo." << endl;
            continue;
        }
        ptr->Speak();
        delete ptr;
    }
    return 0;
}