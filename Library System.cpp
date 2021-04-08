//Simple library system

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>


using namespace std;

//Common Variables
int select; int add_book = 1; int add_user = 1; int borrow_count = 0;
string book_to_search; string category_to_find; string book_user;
char y_or_n;

//Struct for Books
struct book {
	int book_id; int book_quantity;
	string book_name; string book_category;

	void read_book() {
		cout << "Enter book_id , book_name , book_category "<<endl;
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
	void print_users() {
		cout << " Users of library :" << endl;
			cout << "User id : " <<user_id <<" , ";
			cout << "User name : " <<user_name << endl;
	}
	
};
struct borrowd {
	string borrow_book;
	string borrow_user;
};

//Arrays and variables based on struct
book Books_array[100];
user Users_array[100];
borrowd Borrows_array[100];
borrowd b_book;

//Function to find book
void search_for_book(string book_to_search) {
	cout << "Enter book's name"<<endl;
	cin >> book_to_search;
	for (int i = 1; i <= add_book; i++) {
		if (Books_array[i].book_name == book_to_search) {
			cout << "Book Found : " << Books_array[i].book_name << endl;
			break;
			if (i > add_book) {
				cout << "Book isn't found" << endl;
			}
		}		
}
}
//Founction to find category
void search_for_category(string category_to_find) {
	cout << "Enter category" << endl;
	cin >> category_to_find;
	for (int i = 1; i <= add_book; i++) {
		if (Books_array[i].book_category == category_to_find) {
			cout << "Books : " << Books_array[i].book_category << endl;
			break;
			if (i > add_book) {
				cout << "category isn't found" << endl;
			}
		}
	}
}




int main()
{
	//Show library operations
	cout << "[1] Add a book."<<endl;
	cout << "[2] Add user." << endl;
	cout << "[3] Search for book." << endl;
	cout << "[4] Show books by category." << endl;
	cout << "[5] Borrow a book." << endl;
	cout << "[6] return a book." << endl;
	cout << "[7] Show who borrowed a specific book." << endl;
	cout << "[8] print users" << endl;
	cout << "[9] Exit" << endl;
jump:
	cout << endl<<"Enter num of operation :  "<<endl;
	cin >> select;
	//Main operations 
	switch (select)
	{
	case 1 :
		Books_array[add_book].read_book();
		add_book++;
		break;

	case 2:
		add_user :
		Users_array[add_user].read_user();
		add_user++;
		break;
	case 3 :
		search_for_book(book_to_search);
		break;
	case 4 :
		search_for_category(category_to_find);
		break;
	case 5:
		//Remember to remove book from array
		cout << "Enter Book's name , User's name : " << endl;
		cin >> b_book.borrow_book >> b_book.borrow_user;
		//Check user
		for (int i = 1; i < add_user; i++) {
			if (b_book.borrow_user != Users_array[i].user_name) {
				cout << "User isn't found, You can add it : " << endl;
				goto add_user;
			}
		}
		//Borrow
			for (int i = 1; i <= add_book; i++) {
				if (Books_array[i].book_name == b_book.borrow_book){
					Borrows_array[borrow_count++] = b_book;
				cout << " Book has been borrowd ! " << endl;
				}
				else
					cout << "Book isn't found ! " << endl;
			}
		break;
	case 7 :
		cout << " Enter book name : " << endl;
		cin >> book_user;
		for (int i = 0; i < borrow_count; i++) {
			if (Borrows_array[i].borrow_book == book_user) {
				cout << "The user is : " << Borrows_array[i].borrow_user << endl;
			}
		}
		break;
	case 8:
		for (int k = 1; k < add_user; k++) {
			Users_array[k].print_users();
		}
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

