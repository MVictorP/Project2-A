// Name: Pearson, Matthew
// Project: 2A
 
#pragma once
#include "Book.h"

class Library {

private:
	list<Customer*> customerList;
	list<Book> freshBooks;
	list<Book> archived;

public:
	Library();
	~Library();
	void add_customer(string newCustomer);
	void add_book(string newBook);
	void pass_next(string chosenBook, Date date);
	void circulate_book(string chosenBook, Date transferDate);
};