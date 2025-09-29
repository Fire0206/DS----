#include<iostream>
#include<string>
using namespace std;
class Document {
protected:
	string name;
public:
	Document() {
		cout << "Create Document Class" << endl;
	}
	~Document() {
		cout << "Delete Document Class" << endl;
	}
	void Print() {
		cout << name << endl;
	}
};

int main() {
	class Book :public Document {
	protected:
		int pageCount;
	public:
		Book(string a,int b) {
			name = a;
			pageCount = b;
			cout << "Create Book Class" << endl;
		}
		~Book() {
			cout << "Delete Book Class" << endl;
		}
		void Print() {
			cout << "Document Name is "<<name << endl;
			cout << "PageCount is " << pageCount << endl;
		}
	};
	string a;
	int b;
	cin >> a >> b;
	Book book(a, b);
	book.Print();
	return 0;
}