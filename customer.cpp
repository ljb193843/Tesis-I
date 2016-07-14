#include "customer.h"

#define CUSTOMERS 50

customer::customer(int i, int x, int y, int del, int pick, float ady[CUSTOMERS], bool l):
		id(i), xi(x), yi(y), delivery(del), pickup(pick), adyacencia[CUSTOMERS](ady[CUSTOMERS]), l{
	}