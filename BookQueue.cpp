// Name: Pearson, Matthew
// Project: 2A

#include "BookQueue.h"

BookQueue::BookQueue()
{
}

void BookQueue::addCustomer(Customer* tmp)
{
	WaitingQueue.push_back(tmp); // adds customer to WaitingQueue (waiting to get book)
}

Customer* BookQueue::dequeue()
{
	Customer *front = *WaitingQueue.begin(); // create pointer to beginning of WaitingQueue
	vector<Customer*>::iterator iter, removeFront;
	iter = removeFront = WaitingQueue.begin();
	iter++; // iter now starts at position after the front
	for (iter; iter != WaitingQueue.end(); iter++)
	{
		if ((front->getCustomerWait() - front->getCustomerRetain()) < ((*iter)->getCustomerWait() - (*iter)->getCustomerRetain())) // check to assign priority based waiting and retaing times
		{
			front = *iter;
			removeFront = iter;
		}
	}
	WaitingQueue.erase(removeFront); // remove front of WaitingQueue
	return front;
}

Customer* BookQueue::start()
{
	Customer *front = *WaitingQueue.begin(); // create pointer to beginning of WaitingQueue
	vector<Customer*>::iterator iter = WaitingQueue.begin();
	iter++; // iter now starts at position after the front
	for (iter; iter != WaitingQueue.end(); iter++)
	{
		if ((front->getCustomerWait() - front->getCustomerRetain()) < ((*iter)->getCustomerWait() - (*iter)->getCustomerRetain())) // check to assign priority based waiting and retaing times
		{
			front = *iter;
		}
	}
	return front;
}

bool BookQueue::empty()
{
	return WaitingQueue.size() < 1; // check if WaitingQueue is empty or not
}