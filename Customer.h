// Name: Pearson, Matthew
// Project: 2A

#pragma once
#include "Date.h"
#include "omp.h"
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Customer {

private:
	string customerName;
	int customerWaitTime;
	int customerRetainTime;

public:
	Customer();
	Customer(string newCustomerName);
	const Customer& operator=(const Customer& rhs);
	void setCustomerName(string setCustomerName);
	void setCustomerWait(int setCustomerWait);
	void setCustomerRetain(int setCustomerRetain);
	void waitTotal(int newWait);
	void retainTotal(int newRetain);
	string getCustomerName();
	int getCustomerWait();
	int getCustomerRetain();
	friend bool operator<(const Customer& lhs, const Customer& rhs);
};

