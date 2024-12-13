#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;
enum class BookType {
    Fiction,
    Technical
};
class Book {
private:
    string author;
    string title;
    BookType type;

public:
    Book(const string& authorName, const string& bookTitle, BookType
        bookType) {
        if (authorName.empty() || bookTitle.empty()) {
            throw invalid_argument("Автор и название книги не могут быть пустыми.");
        }
        author = authorName;
        title = bookTitle;
        type = bookType;
    }
    BookType getType() const {
        return type;
    }
};
void outputBookCounts(const vector<Book>& library) {
    int fictionCount = 0;
    int technicalCount = 0;
    for (const auto& book : library) {
        switch (book.getType()) {
        case BookType::Fiction:
            ++fictionCount;
            break;
        case BookType::Technical:
            ++technicalCount;
            break;
        }
    }
    cout << "Выберите тип книг для отображения количества:\n";
    cout << "1. Художественная литература\n";
    cout << "2. Техническая литература\n";
    cout << "3. Все книги\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Количество художественной литературы: " <<
            fictionCount << '\n';
        break;
    case 2:
        cout << "Количество технической литературы: " <<
            technicalCount << '\n';
        break;
    case 3:
        cout << "Количество книг по типам:\n";
        cout << "Художественная литература: " << fictionCount <<
            '\n';
        cout << "Техническая литература: " << technicalCount <<
            '\n';
        break;
    default:
        cout << "Некорректный выбор. Пожалуйста, выберите 1, 2 или 3.\n";
        break;
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    try {
        vector<Book> library;
        library.emplace_back("Александр Пушкин", "Евгений Онегин",
            BookType::Fiction);
        library.emplace_back("Лев Толстой", "Война и мир",
            BookType::Fiction);
        library.emplace_back("Бьёрн Страуструп", "Язык программирования C++", BookType::Technical);
        library.emplace_back("Эндрю Таненбаум", "Архитектура компьютера", BookType::Technical);
        library.emplace_back("Фёдор Достоевский", "Преступление и наказание", BookType::Fiction);
        outputBookCounts(library);
    }
    catch (const exception& ex) {
        cerr << "Ошибка: " << ex.what() << '\n';
    }
    return 0;
}