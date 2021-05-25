//Simple library system

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <iterator>


using namespace std;

//Common Variables
int select;
string book_to_search; string category_to_print; string book_user;
char y_or_n;

//Struct for Books
struct book {
	int book_id; int book_quantity;
	string book_name; string book_category;

	void read_book() {
		cout << "Enter book_id , book_name , book_category " << endl;
		cin >> book_id >> book_name >> book_category;
	}
};

//Struct for Users 
struct user {
	int user_id;
	string user_name;

	void read_user() {
		cout << "Enter user_id , user_name " << endl;
		cin >> user_id >> user_name;
	}

};
//Struct for Borrowed books
struct borrowd {
	string borrow_book;
	string borrow_user;
};

//Vectors based on structs 
vector <book> Books_vector;
book new_book;

vector <user> User_vector;
user new_user;

vector <borrowd> Borrow_vector;
borrowd b_book;

//Function to print users
void print_users(vector <user> &User_vector) {
	vector<user>::iterator it;
	cout << " Users of library :" << endl;
	it = User_vector.begin();
	while (it != User_vector.end()) {
		cout << it - User_vector.begin() << endl;
		it++;
	}
}

//Function to find book
void search_for_book(string book_to_search) {
	cout << "Enter book's name" << endl;
	cin >> book_to_search;
	for (int i = 0; i < Books_vector.capacity(); i++) {
		if (Books_vector[i].book_name == book_to_search) {
			cout << " Book Found : " << book_to_search << endl;
		}
		else if (i == Books_vector.capacity())
			cout << " Book isn't found ! " << endl;
	}
}
//Founction to print by category
void print_by_category(string category_to_print) {
	cout << "Enter category" << endl;
	cin >> category_to_print;
	for (int i = 0; i < Books_vector.capacity(); i++) {
		if (Books_vector[i].book_category == category_to_print) {
			cout << Books_vector[i].book_name;
		}
	}
}

int main()
{
	//Show library operations
	cout << "[1] Add a book." << endl;
	cout << "[2] Add user." << endl;
	cout << "[3] Search for book." << endl;
	cout << "[4] Show books by category." << endl;
	cout << "[5] Borrow a book." << endl;
	cout << "[6] return a book." << endl;
	cout << "[7] Show who borrowed a specific book." << endl;
	cout << "[8] print users" << endl;
	cout << "[9] Exit" << endl;
jump:
	cout << endl << "Enter num of operation :  " << endl;
	cin >> select;

	//Main operations 
	switch (select)
	{
	case 1:
	add_book:
		new_book.read_book();
		Books_vector.push_back(new_book);
		break;

	case 2:
	add_user:
		new_user.read_user();
		User_vector.push_back(new_user);
		break;
	case 3:

		search_for_book(book_to_search);
		break;
	case 4:
		print_by_category(category_to_print);
		break;
	case 5:
		cout << "Enter Book's name , User's name : " << endl;
		cin >> b_book.borrow_book >> b_book.borrow_user;
		//Check user
		for (int i = 0; i < Books_vector.capacity(); i++) {
			if (b_book.borrow_user != User_vector[i].user_name) {
				cout << "User isn't found, You can add it : " << endl;
				goto add_user;
			}
		}
		//Borrow progress
		for (int i = 0; i <= Books_vector.capacity(); i++) {
			if (Books_vector[i].book_name == b_book.borrow_book) {
				Borrow_vector.push_back(b_book);
				Books_vector.erase(Books_vector.begin() + i);
				cout << " Book has been borrowd ! " << endl;
			}
		}
		break;
	case 6:
		cout << "Enter Book's name , User's name : " << endl;
		cin >> b_book.borrow_book >> b_book.borrow_user;
		//Remove from Borrow
		for (int i = 1; i <= Books_vector.capacity(); i++) {
			if (Borrow_vector[i].borrow_book == b_book.borrow_book) {
				Borrow_vector.erase(Borrow_vector.begin() + i);
				cout << " Now, please add the book again ! " << endl;
				goto add_book;
			}
		}
	case 7:
		cout << " Enter book name : " << endl;
		cin >> book_user;
		for (int i = 0; i < Books_vector.capacity(); i++) {
			if (Borrow_vector[i].borrow_book == book_user) {
				cout << "The user is : " << Borrow_vector[i].borrow_user << endl;
			}
		}
		break;
	case 8:
		print_users(User_vector);
	break_code:
	case 9:
		return 0;
	}

	//Function to do another operation
	cout << "Do you want to perform another operation ? [Y] - [N] " << endl;
	y_or_n = _getche();
	if (y_or_n == 'y' || y_or_n == 'Y')
		goto jump;
	else if (y_or_n == 'n' || y_or_n == 'N')
		return 0;


	system("Pause");
	return 0;
}
