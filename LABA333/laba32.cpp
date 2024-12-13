#include <iostream> 
#include <vector> 
#include <memory> 
#include <cstdlib> 
#include <ctime> 

using namespace std;

class Base {
protected:
    Base() {}
public:
    virtual ~Base() {}
    virtual void show() const = 0;
};

class Derived : public Base {
protected:
    Derived() {}
public:
    ~Derived() override {}
    void show() const override {
        cout << "Это Derived." << endl;
    }

    static shared_ptr<Derived> create() {
        return shared_ptr<Derived>(new Derived());
    }
};

class ConcreteBase : public Base {
protected:
    ConcreteBase() {}
public:
    ~ConcreteBase() override {}
    void show() const override {
        cout << "Это ConcreteBase." << endl;
    }

    static shared_ptr<ConcreteBase> create() {
        return shared_ptr<ConcreteBase>(new ConcreteBase());
    }
};

template <typename T>
void addToStorage(vector<shared_ptr<Base>>& storage, T element) {
    storage.push_back(element);
}
int main() {
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned int>(time(0)));
    vector<shared_ptr<Base>> storage;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand();
        if (randomNumber % 2 == 0) {
            addToStorage(storage, ConcreteBase::create());
        }
        else {
            addToStorage(storage, Derived::create());
        }
    }
    for (const auto& item : storage) {
        item->show();
    }
    storage.clear();
    return 0;
}