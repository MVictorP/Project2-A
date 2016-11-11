// Name: Pearson, Matthew
// Project: 2A

#include "Book.h"

Book::Book() 
{
}

Book::Book(string BookName) 
{
	bookName = BookName;
}

Book::Book(string BookName, Date begin) 
{
	bookName = BookName;
	checkoutDate = begin;
}

Book::Book(const Book& newBook) 
{
	bookName = newBook.bookName;
	checkoutDate = newBook.checkoutDate;
	checkinDate = newBook.checkinDate;
	isArchived = newBook.isArchived;
	contents = newBook.contents;
}

string Book::getBookName() 
{
	return bookName;
}

Date Book::getDateHeldLast()
{
	return dateHeldLast;
}

Date Book::getCheckoutDate() 
{
	return checkoutDate;
}

Date Book::getCheckinDate() 
{
	return checkinDate;
}

bool Book::getIsArchived() 
{
	return isArchived;
}

void Book::setBookName(string newBookName) 
{
	bookName = newBookName;
}

void Book::setDateHeldLast(Date newBookDate)
{
	dateHeldLast = newBookDate;
}

void Book::setCheckoutDate(Date newCheckoutDate) 
{ 
	checkoutDate = dateHeldLast = newCheckoutDate;
}

void Book::setCheckinDate(Date newCheckinDate) 
{
	checkinDate = newCheckinDate;
}

void Book::setIsArchived(bool newBoolean) 
{
	isArchived = newBoolean;
}

Customer* Book::dequeue() 
{
	return contents.dequeue();
}

Customer* Book::start() 
{
	return contents.start();
}

bool Book::isEmpty() 
{
	return contents.empty();
}

void Book::produceQueue(const list<Customer*> customerList)
{
	list<Customer*>::const_iterator iter;
#pragma omp parallel
	{
#pragma omp single
		{
			for (iter = customerList.begin(); iter != customerList.end(); iter++)
			{
				contents.addCustomer(*iter); // iterate through each customer and add them to waitingQueue
			}
		}
	}
}