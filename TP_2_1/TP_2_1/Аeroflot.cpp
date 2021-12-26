#include "Аeroflot.h"

Аeroflot::Аeroflot() : destination("Не задано"), type("Не задано"), number("Не задано")
{
	cout << "Вызван конструктор Аeroflot" << endl;
}

Аeroflot::Аeroflot(string destination, string type, string number) :
	destination(destination), type(type), number(number)
{
	cout << "Вызван конструктор Аeroflot" << endl;
}

Аeroflot::Аeroflot(const Аeroflot& aeroflot) :
	destination(aeroflot.destination), type(aeroflot.type), number(aeroflot.number)
{
	cout << "Вызван конструктор копирования Аeroflot" << endl;
}

Аeroflot::~Аeroflot()
{
	cout << "Вызван деструктор Аeroflot" << endl;
}

void Аeroflot::inputFromConsole()
{
	cout << "Введите пункт назначения: ";
	getline(cin, destination);
	cout << "Введите номер рейса: ";
	getline(cin, number);
	cout << "Введите тип самолета: ";
	getline(cin, type);
}

void Аeroflot::printToConsole()
{
	cout << "Пункт назначения: " << destination << endl;
	cout << "Номер рейса: " << number << endl;
	cout << "Тип самолета: " << type << endl;
}

void Аeroflot::change()
{
	cout << "Введите новый пункт назначения: ";
	getline(cin, destination);
	cout << "Введите новый номер рейса: ";
	getline(cin, number);
	cout << "Введите новый тип самолета: ";
	getline(cin, type);
}

Аeroflot& Аeroflot::operator=(const Аeroflot& aeroflot) {
	if (this == &aeroflot)
		return *this;
	destination = aeroflot.destination;
	type = aeroflot.type;
	number = aeroflot.number;
	return *this;
}

bool Аeroflot::operator>(const Аeroflot& aeroflot) {
	return destination > aeroflot.destination;
}