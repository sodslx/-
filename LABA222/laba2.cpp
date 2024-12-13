#include <iostream> 
#include <string> 
using namespace std;
class Publication 
{
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
class Book : public Publication {
private:
	int page_count;
public:
	void getdata() {
		Publication::getdata();
		cout << "Enter the number of pages: ";
		cin >> page_count;
		cin.ignore();
	}
	void putdata() const {
		Publication::putdata();
		cout << "Number of pages: " << page_count << endl;
	}
};
class Tape : public Publication {
private:
	float play_time;
public:
	void getdata() {
		Publication::getdata();
		cout << "Enter the play time in minutes: ";
		cin >> play_time;
		cin.ignore();
	}
	void putdata() const {
		Publication::putdata();
		cout << "Play time: " << play_time << " minutes" << endl;
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