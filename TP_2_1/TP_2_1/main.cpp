#include "Аeroflot.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Аeroflot>& aeroflots);
void changeObject(Marray<Аeroflot>& aeroflots);
void deleteObject(Marray<Аeroflot>& aeroflots);
void print(Marray<Аeroflot>& aeroflots);
void searchObjects(Marray<Аeroflot>& aeroflots);
void checkWeather();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Аeroflot> aeroflots;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(aeroflots);
			break;
		case 2:
			changeObject(aeroflots);
			break;
		case 3:
			deleteObject(aeroflots);
			break;
		case 4:
			print(aeroflots);
			break;
		case 5:
			searchObjects(aeroflots);
			break;
		case 6:
			checkWeather();
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Найти рейс по пункту типу самолета" << endl;
	cout << "6. Проверить погоду" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Аeroflot>& aeroflots) {
	Аeroflot student;
	student.inputFromConsole();
	aeroflots += student;
	aeroflots.sort();
}

void changeObject(Marray<Аeroflot>& aeroflots) {
	if (aeroflots.getSize() > 0) {
		print(aeroflots);
		cout << "Введите номер рейса для изменения: ";
		aeroflots[safeInput(1, aeroflots.getSize()) - 1].change();
	}
	else
		cout << "Список рейсов пуст. Нечего изменять\n";
	aeroflots.sort();
}

void deleteObject(Marray<Аeroflot>& aeroflots) {
	if (aeroflots.getSize() > 0) {
		print(aeroflots);
		cout << "Введите номер рейса для удаления: ";
		aeroflots -= safeInput(1, aeroflots.getSize()) - 1;
	}
	else
		cout << "Список рейсов пуст. Нечего удалять\n";
	aeroflots.sort();
}

void print(Marray<Аeroflot>& aeroflots) {
	if (aeroflots.getSize() == 0)
		cout << "Список рейсов пуст.\n";
	else {
		cout << "Список рейсов\n";
		for (int i = 0; i < aeroflots.getSize(); i++) {
			cout << i + 1 << ". Рейс\n";
			aeroflots[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Аeroflot>& aeroflots) {
	if (aeroflots.getSize() == 0)
		cout << "Список рейсов пуст\n";
	else {
		bool isPrint = false;
		cout << "Введите пункт тип самолета, который хотите найти: ";
		string type;
		getline(cin, type);
		for (int i = 0; i < aeroflots.getSize(); i++)
			if (aeroflots[i].getType() == type) {
				isPrint = true;
				cout << aeroflots[i].getDestination() << " " << aeroflots[i].getNumber() << endl;
			}
		if (!isPrint)
			cout << "Рейса с таким типом самолета не найдено назначения не найдено\n";
	}
}

void checkWeather() {
	string wheather[8] = { "дождь", "ясно", "снег", "облачно", "град", "туман", "метель", "гроза" };
	//srand(time(NULL));
	int curWeather = rand() % 8;
	if (curWeather > 3)
		cout << "Рейсы временно отменены из-за того, что сейчас " << wheather[curWeather] << endl;
	else
		cout << "Сейчас " << wheather[curWeather] << " все рейсы по расписанию" << endl;
}