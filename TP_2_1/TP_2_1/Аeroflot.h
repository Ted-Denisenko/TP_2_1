#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;

class 픢roflot
{
private:
	string destination, type, number;
public:
	픢roflot();
	픢roflot(string destination, string type, string number);
	픢roflot(const 픢roflot& student);
	~픢roflot();

	void inputFromConsole();
	void printToConsole();
	void change();

	string getDestination() { return destination; }
	void setDestination(string destination) { this->destination = destination; }

	string getType() { return type; }
	void setType(string type) { this->type = type; }

	string getNumber() { return number; }
	void setNumber(string number) { this->number = number; }

	픢roflot& operator=(const 픢roflot& student);
	bool operator>(const 픢roflot& aeroflot);
};

