#include <iostream>
#include "automata.h"
using namespace std;

Automata::Automata() {
	printState();
};

void Automata::printState() {
	switch (state) {
			case(off):
				cout << "������� ��������." << endl;
				cash = 0;
				turned_off();
		break;

			case(wait):
				cout << "�������� ��������:" << endl;
				turn_off();
				break;

			case(accept):
				cout << "�������� ������: ";
				cin >> money;
				coin(money);

				cout << "�������� ������� �� ������ ����: " << endl;
				printMenu();
				cin >> i;
				choice(i);
				break;

			case(check):
				cout << "��������: " << endl;
				checking();
				break;

			case(cook):
				cout << "�������..." << endl;
				finish();
				break;

			default: cout << " ����������� ������." << endl;
	};
};

void Automata::on() {
	cout << "���������... ����� ����������. " << endl;
	exit = "";
	state = wait;
	printState();
};

void Automata::coin(int money) {
	cash += money;
	cout << "������� " << cash << " �����.\n" << endl;
};

void Automata::printMenu() {
	for (i = 0; i < 6; i++) {
		cout << i + 1 << ". " << menu[i]
			<< "\t" << price[i] << " �����." << endl;
	};
	i = 0;
};

void Automata::choice(int i) {
	cout << "�� ������� "
		<< menu[i - 1] << " �������.\n" << endl;
	state = check;
	printState();
};

void Automata::checking() {
	if (cash >= price[i - 1]) {
		cash -= price[i - 1];
		cooking();
	}
	else {
		cout << "������������ �������.";
		cancel();
	};
	printState();
};

void Automata::cancel() {
	cout << " ������. " << endl;
	state = wait;
	printState();
};

void Automata::cooking() {
	state = cook;
	printState();
};

void Automata::finish() {
	cout << "��� ������� " << menu[i - 1] << " ���������... ";
	cout << "�������� �������." << endl;
	state = wait;
};

void Automata::turn_off() {
	cout << "������ ��������� �������? [��/���]" << endl;
	cin >> exit;
	if (exit == "���") {
		cout << "������ �� ����� " << cash << " �����." << endl;
		state = accept;
		printState();
	}
	else {
		cout << "Good Bye!" << endl;
	}
};

void Automata::turned_off() {
	cout << "������ ��������? [��/���]" << endl;
	cin >> exit;

	if (exit == "��") {
		on();
	}
};
Automata::~Automata() { };