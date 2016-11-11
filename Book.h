// Name: Pearson, Matthew
// Project: 2A

#pragma once
#include "BookQueue.h"

class Book {

private:
	string bookName;
	BookQueue contents;
	bool isArchived;
	Date checkoutDate;
	Date checkinDate;
	Date dateHeldLast;

public:
	Book();
	Book(string bookName);
	Book(string bookName, Date begin);
	Book(const Book& newBook);
	string getBookName();
	bool getIsArchived();
	Date getCheckoutDate();
	Date getCheckinDate();
	Date getDateHeldLast();
	void setBookName(string newBookName);
	void setDateHeldLast(Date newBookDate);
	void setCheckoutDate(Date newCheckoutDate);
	void setCheckinDate(Date newCheckinDate);
	void setIsArchived(bool newBoolean);
	Customer* dequeue();
	Customer* start();
	bool isEmpty();
	void produceQueue(list<Customer*> customerList);
};
