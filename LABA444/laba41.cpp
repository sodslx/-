#include <iostream> 
#include <vector> 
#include <memory> 
using namespace std;
class Error {
public:
    virtual void printError() const = 0;
    virtual ~Error() {}
};
class MemoryAccessError : public Error {
public:
    void printError() const override {
        cout << "Memory Access Error" << endl;
    }
};
class MathError : public Error {
public:
    void printError() const override {
        cout << "Mathematical Error" << endl;
    }
};
class DivisionByZeroError : public MathError {
public:
    void printError() const override {
        cout << "Division by Zero Error" << endl;
    }
};
class OverflowError : public MathError {
public:
    void printError() const override {
        cout << "Overflow Error" << endl;
    }
};
template <typename T>
class PointerArray {
private:
    vector<shared_ptr<T>> elements;
public:
    void addElement(shared_ptr<T> element) {
        elements.push_back(element);
    }
    shared_ptr<T> operator[](size_t index) const {
        if (index >= elements.size()) {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }
    size_t size() const {
        return elements.size();
    }
};
int main() {
    try {
        shared_ptr<Error> memError = make_shared<MemoryAccessError>();
        shared_ptr<Error> mathError = make_shared<MathError>();
        shared_ptr<Error> divZeroError = make_shared<DivisionByZeroError>();
        shared_ptr<Error> overflowError = make_shared<OverflowError>();
        PointerArray<Error> errorArray;
        errorArray.addElement(memError);
        errorArray.addElement(mathError);
        errorArray.addElement(divZeroError);
        errorArray.addElement(overflowError);
        for (size_t i = 0; i < errorArray.size(); ++i) {
            errorArray[i]->printError();
        }
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}