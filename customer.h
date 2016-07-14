#include <iostream>
#define CUSTOMERS 55
#define TOPEVECTOR 200
#define FALSE 0
#define TRUE 1

typedef struct customer
{
	int id;
	int xi;
	int yi;
	int Delivery;
	int Pickup;
	float adyacencia[CUSTOMERS];
	bool L=TRUE;
};
