// Name: Pearson, Matthew
// Project: 2A

#include "Customer.h"

Customer::Customer() 
{
	customerName = "";
	customerWaitTime = 0;
	customerRetainTime = 0;
}

Customer::Customer(string newCustomerName) 
{
	customerName = newCustomerName;
	customerWaitTime = 0;
	customerRetainTime = 0;
}

const Customer& Customer::operator=(const Customer& rhs) 
{
	customerName = rhs.customerName;
	customerWaitTime = rhs.customerWaitTime;
	customerRetainTime = rhs.customerRetainTime;
	return *this;
}

void Customer::setCustomerName(string setCustomerName) 
{
	customerName = setCustomerName;
}

void Customer::setCustomerWait(int setCustomerWait)
{
	customerWaitTime = setCustomerWait;
}

void Customer::setCustomerRetain(int setCustomerRetain)
{
	customerRetainTime = setCustomerRetain;
}

void Customer::waitTotal(int newWait) 
{
	customerWaitTime += newWait;
}

void Customer::retainTotal(int newRetain) 
{
	customerRetainTime += newRetain;
}

string Customer::getCustomerName() 
{
	return customerName;
}

int Customer::getCustomerWait() 
{
	return customerWaitTime;
}

int Customer::getCustomerRetain() 
{
	return customerRetainTime;
}

bool operator<(const Customer& lhs, const Customer& rhs) 
{
	return ((lhs.customerWaitTime - lhs.customerRetainTime) < (rhs.customerWaitTime - rhs.customerRetainTime));
}