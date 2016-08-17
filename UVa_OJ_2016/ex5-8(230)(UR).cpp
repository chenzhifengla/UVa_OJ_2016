#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
using namespace std;

struct Book {
	string title;
	vector<string> authors;
	bool operator < (const Book& b) const {
		if (this->title != b.title) return this->title < b.title;
		else {
			for (int i = 0; i < this->authors.size() && i < b.authors.size(); i++) {
				if (this->authors[i] != b.authors[i]) {
					return this->authors[i] < b.authors[i];
				}
			}
			return this->authors.size() < b.authors.size();
		}
	}
};

struct cmp {
	bool operator() (const Book a, const Book b) const {
		if (a.title != b.title) return a.title < b.title;
		else {
			for (int i = 0; i < a.authors.size() && i < b.authors.size(); i++) {
				if (a.authors[i] != b.authors[i]) {
					return a.authors[i] < a.authors[i];
				}
			}
			return a.authors.size() < b.authors.size();
		}
	}
};

vector<Book> shelve;
map<string, Book> borrowed;
priority_queue<Book, vector<Book>, cmp > returned;
vector<bool> inShelve;



void borrow(string title) {
	for (int i = 0; i < shelve.size(); i++) {
		if (shelve[i].title == title) {
			inShelve[i] = false;
			borrowed[title] = shelve[i];
		}
		break;
	}
}

void return_(string title) {
	returned.push(borrowed[title]);
	borrowed.erase(title);
}

void shelveBook() {
	while (!returned.empty()) {
		Book book = returned.top();
		returned.pop();
		int index = 0;
		for (; index < shelve.size(); index++) {
			if (shelve[index].title == book.title) {
				inShelve[index] = true;
				break;
			}
		}
		int before = -1;
		for (int i = index - 1; i >= 0; i--) {
			if (inShelve[i]) {
				before = i;
				break;
			}
		}
		cout << "Put " << book.title << " ";
		if (before < 0) cout << "first" << endl;
		else cout << "after " << shelve[before].title << endl;
	}
}

int main() {
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		string title;
		ss >> title;	//此处title中包含空格，怎么处理进去
		if (title == "END") break;
		string temp, author;
		vector<string> authors;
		while (ss >> temp) {
			ss >> author;
			authors.push_back(author);
		}
		Book book;
		book.title = title;
		book.authors = authors;
		shelve.push_back(book);
		inShelve.push_back(true);
	}
	sort(shelve.begin(), shelve.end());
	while (getline(cin, line)) {
		stringstream ss(line);
		string command;
		ss >> command;
		if (command == "END") break;
		if (command == "SHELVE") {
			shelveBook();
		}
		else {
			string title;
			ss >> title;
			if (command == "BORROW") {
				borrow(title);
			}
			else if (command == "RETURN") {
				return_(title);
			}
		}
	}
	return 0;
}