#include <iostream> 
#include <vector> 
#include <memory> 

using namespace std;

class Detail {
protected:
    Detail() {}
public:
    virtual ~Detail() {}
    virtual void show() const = 0;
};

class Assembly : public Detail {
protected:
    Assembly() {}
public:
    ~Assembly() override {}
    void show() const override {
        cout << "Это сборка." << endl;
    }
};

class ConcreteDetail : public Detail {
protected:
    ConcreteDetail() {}
public:
    ~ConcreteDetail() override {}
    void show() const override {
        cout << "Это конкретная деталь." << endl;
    }
    static shared_ptr<ConcreteDetail> create() {
        return shared_ptr<ConcreteDetail>(new ConcreteDetail());
    }
};

class ConcreteAssembly : public Assembly {
protected:
    ConcreteAssembly() {}
public:
    ~ConcreteAssembly() override {}
    void show() const override {
        cout << "Это конкретная сборка." << endl;
    }
    static shared_ptr<ConcreteAssembly> create() {
        return shared_ptr<ConcreteAssembly>(new ConcreteAssembly());
    }
};

template <typename T>
void addToStorage(vector<shared_ptr<Detail>>& storage, T element) {
    storage.push_back(element);
}
    int main() {
        setlocale(LC_ALL, "rus");
        vector<shared_ptr<Detail>> storage;
        addToStorage(storage, ConcreteDetail::create());
        addToStorage(storage, ConcreteAssembly::create());
        for (const auto& item : storage) {
            item->show();
        }
        return 0;
    }
