// Name: Pearson, Matthew
// Project: 2A

#pragma once
#include "Customer.h"

class BookQueue {

private:
	vector<Customer*> WaitingQueue;

public:
	BookQueue();
	void addCustomer(Customer* tmp);
	Customer* dequeue();
	Customer* start();
	bool empty();
};