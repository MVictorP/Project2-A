// Name: Pearson, Matthew
// Project: 2A

#include "Library.h"

Library::Library()
{
}

Library::~Library()
{
	list<Customer*>::iterator iter;
#pragma omp parallel
	{
#pragma omp single
		{
			for (iter = customerList.begin(); iter != customerList.end(); iter++)
			{
				delete *iter;
			}
		}
	}
}

void Library::add_customer(string newCustomer)
{
	Customer *tmp;
	tmp = new Customer(newCustomer); // pass customer into tmp
	customerList.push_front(tmp); // add customer to customerList
}

void Library::add_book(string newBook)
{
	Book tmpBook(newBook); // create new Book
	freshBooks.push_back(tmpBook); // add book to uncirculatedBooks
}

void Library::pass_next(string chosenBook, Date date)
{
	Customer *Next, *Prev;
	list<Book>::iterator iter;
#pragma omp parallel
	{
#pragma omp single
		{
			for (iter = freshBooks.begin(); iter != freshBooks.end(); iter++)
			{
				if (iter->getBookName() == chosenBook) // check if iter's book name against the name of the chosenBook
				{
					Prev = iter->dequeue(); // remove item at front and save it to Prev
					Prev->retainTotal(date - iter->getDateHeldLast()); // calculate the time retained
					if (!iter->isEmpty()) // while iter is not empty
					{
						Next = iter->start(); // move to front and save item to Next
						Next->waitTotal(date - iter->getCheckoutDate()); // calculate the time waited
						iter->setDateHeldLast(date); // change dateHeldLast to date passed in
					}
					else
					{
						iter->setIsArchived(true); // isArchived = True for current iter
						iter->setCheckinDate(date); // change checkinDate to date passed in for current iter
						archived.push_back(*iter); // add current iter to archived list
						freshBooks.erase(iter); // remove current iter from uncirculatedBooks list
						list<Customer*>::iterator iter;
						for (iter = customerList.begin(); iter != customerList.end(); iter++) // iterate through those who held the book
						{
							(*iter)->setCustomerWait(0); // reset each persons waiting time to 0
							(*iter)->setCustomerRetain(0); // reset each persons retaining time to 0
						}
					}
					break;
				}
			}
		}
	}
}

void Library::circulate_book(string chosenBook, Date transferDate)
{
	list<Book>::iterator iter;
#pragma omp parallel
{
#pragma omp single
	{
		for (iter = freshBooks.begin(); iter != freshBooks.end(); iter++)
		{
			if (iter->getBookName() == chosenBook) // if the current iteration is the book to be circulated
			{
				iter->produceQueue(customerList); // add WaitingQueue to current iter
				iter->setCheckoutDate(transferDate); // sets transferDate to iter's date
				break;
			}
		}
	}
}
}