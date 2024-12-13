#include <iostream> 
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n <= 0) {
        cerr << "Некорректное количество элементов.\n";
        return 1;
    }
    int* arr = new int[n];
    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Содержимое массива:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    cout << "Адрес начала массива: " << static_cast<void*>(arr) <<
        '\n';
    cout << "Адреса элементов и их расстояние от начала массива (в байтах):\n"; 
        for (int i = 0; i < n; ++i) {
            void* current_address = static_cast<void*>(arr + i);
            ptrdiff_t distance_in_bytes = reinterpret_cast<char*>(arr + i) - reinterpret_cast<char*>(arr);
            cout << "Элемент " << i << " находится по адресу: "
                << current_address
                << ", расстояние от начала: " << distance_in_bytes << "байт\n"; 
        }
    delete[] arr;
    return 0;
}