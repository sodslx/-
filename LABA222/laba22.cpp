#include <iostream> 
#include <string> 
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter the title: ";
        getline(cin, title);
        cout << "Enter the price: ";
        cin >> price;
        cin.ignore();
    }
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << " USD" << endl;
    }
};
class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        cout << "Enter sales for the last three months:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << (i + 1) << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }
    void putdata() const {
        cout << "Sales for the last three months: " << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << (i + 1) << ": " << sales[i] << " USD"
                << endl;
        }
    }
};
class Book : public Publication, public Sales {
private:
    int page_count;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the number of pages: ";
        cin >> page_count;
        cin.ignore();
        Sales::getdata();
    }
        void putdata() const {
            Publication::putdata();
            cout << "Number of pages: " << page_count << endl;
            Sales::putdata();
        }
    };
    class Tape : public Publication, public Sales {
    private:
        float play_time;
    public:
        void getdata() {
            Publication::getdata();
            cout << "Enter the play time in minutes: ";
            cin >> play_time;
            cin.ignore();
            Sales::getdata();
        }
        void putdata() const {
            Publication::putdata();
            cout << "Play time: " << play_time << " minutes" << endl;
            Sales::putdata();
        }
    };
    int main() {
        Book book;
        Tape tape;
        cout << "Enter details for book:\n";
        book.getdata();
        cout << "\nDetails of the book:\n";
        book.putdata();
        cout << "\nEnter details for tape:\n";
        tape.getdata();
        cout << "\nDetails of the tape:\n";
        tape.putdata();
        return 0;
    }