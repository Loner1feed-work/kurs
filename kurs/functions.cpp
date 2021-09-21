#include "functions.h";
using namespace std;

void DataEntry(Data* (&d), int& n) {
	cout << "������� ����������� ������������� ��� ����������: ";
	cin >> n;
	int bool_init;
	int count = 0;
	d = new Data[n];
	system("cls");
	for (int i = 0; i < n; i++) {
		count++;
		cout << "������������ " << count << endl;

		cout << "������� ����� �����: " << endl;
		cin >> d[i].place_number;


		cout << "������� ���: " << endl;
		cin >> d[i].full_name.name;
		cout << "������� �������: " << endl;
		cin >> d[i].full_name.surname;
		cout << "������� ��������: " << endl;
		cin >> d[i].full_name.partonimyc;


		cout << "������� ����� ����������: " << endl;
		cin >> d[i].car_model;

		cout << "������� ���������� �� �������: " << endl;
		cin >> bool_init;
		d[i].car_avaliability = (bool_init == 1) ? true : false;

		cout << "������� ������ �� ������� �����: " << endl;
		cin >> bool_init;
		d[i].payment_avaliability = (bool_init == 1) ? true : false;
		system("cls");
	}

	ofstream out;
	out.open("../base.txt");

	if (out.is_open()) {
		out << n << endl;
	}

	for (int i = 0; i < n; i++) {
		if (out.is_open())
		{
			//����� ����� �� �����������
			out << d[i].place_number << endl;

			//��� ��������� ����������
			out << d[i].full_name.name << " ";
			out << d[i].full_name.surname << " ";
			out << d[i].full_name.partonimyc << endl;

			//����� ����������
			out << d[i].car_model << endl;

			//������� � ������� ���������� �� �������
			out << d[i].car_avaliability << endl;

			//������� �� ������ �� ������� �����
			out << d[i].payment_avaliability << endl;
		}
	}

	out.close();

	cout << "������ ������� �������� � ����!" << endl;

	delete[] d;

	system("pause");


}

void ReadingData(Data* (&d), int& n) {
	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//����������� �������������
			//reading >> n;

			//����� ����� �� �����������
			reading >> d[i].place_number;

			//��� ��������� ����������
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//����� ����������
			reading >> d[i].car_model;

			//������� � ������� ���������� �� �������
			reading >> d[i].car_avaliability;

			//������� �� ������ �� ������� �����
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();

	int count = 1;
	for (int i = 0; i < n; i++) {

		cout << "����� ������������: " << count << endl;

		//����� ����� �� �����������
		cout << "����� ����� �� �����������:" << endl;
		cout << d[i].place_number << endl;

		//��� ��������� ����������
		cout << "��� ��������� ����������:" << endl;
		cout << d[i].full_name.name << " ";
		cout << d[i].full_name.surname << " ";
		cout << d[i].full_name.partonimyc << endl;

		//����� ����������
		cout << "����� ����������:" << endl;
		cout << d[i].car_model << endl;


		//������� � ������� ���������� �� �������
		cout << "������� � ������� ���������� �� �������:" << endl;
		cout << d[i].car_avaliability << endl;

		//������� �� ������ �� ������� �����
		cout << "������� �� ������ �� ������� �����:" << endl;
		cout << d[i].payment_avaliability << endl;

		cout << "_________________________________________________________" << endl;

		count++;
	}

	delete[] d;
}

void AvaliablePlaces(Data* (&d), int& n) {
	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//����������� �������������
			//reading >> n;


			//����� ����� �� �����������
			reading >> d[i].place_number;

			//��� ��������� ����������
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//����� ����������
			reading >> d[i].car_model;

			//������� � ������� ���������� �� �������
			reading >> d[i].car_avaliability;

			//������� �� ������ �� ������� �����
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();

	cout << "������ ��������� ������� �� ������ ������: " << endl;

	for (int i = 0; i < n; i++) {
		if (d[i].car_avaliability == 0) {
			cout << d[i].place_number << endl;
		}
	}
}

void NonPaidUsers(Data* (&d), int& n) {
	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//����������� �������������
			//reading >> n;

			//����� ����� �� �����������
			reading >> d[i].place_number;

			//��� ��������� ����������
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//����� ����������
			reading >> d[i].car_model;

			//������� � ������� ���������� �� �������
			reading >> d[i].car_avaliability;

			//������� �� ������ �� ������� �����
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();

	for (int i = 0; i < n; i++) {
		if (d[i].payment_avaliability == 0) {
			cout << "������������ ������� ��� �������: " << d[i].place_number << endl;

			cout << "���: ";
			cout << d[i].full_name.name <<  " " << d[i].full_name.surname << " " << d[i].full_name.partonimyc << " " << endl;

			cout << "����� ����������: ";
			cout << d[i].car_model << endl;
		}
	}
}

void addInfo(Data* (&d), int& n) {

	int count = 0;
	int bool_init;
	int arrCount = 0;
	int size = 0;

	cout << "������� ����������� ����� ��� ����������: ";
	cin >> arrCount;
	//cout << arrCount << endl;
	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;
		size = n + arrCount;

		d = new Data[size];

		for (int i = 0; i < n; i++) {
			//����������� �������������
			//reading >> n;

			//����� ����� �� �����������
			reading >> d[i].place_number;

			//��� ��������� ����������
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//����� ����������
			reading >> d[i].car_model;

			//������� � ������� ���������� �� �������
			reading >> d[i].car_avaliability;

			//������� �� ������ �� ������� �����
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();

	for (int i = n; i < size; i++) {
		cout << "������������ " << i + 1 << endl;

		cout << "������� ����� �����: " << endl;
		cin >> d[i].place_number;


		cout << "������� ���: " << endl;
		cin >> d[i].full_name.name;
		cout << "������� �������: " << endl;
		cin >> d[i].full_name.surname;
		cout << "������� ��������: " << endl;
		cin >> d[i].full_name.partonimyc;


		cout << "������� ����� ����������: " << endl;
		cin >> d[i].car_model;

		cout << "������� ���������� �� �������: " << endl;
		cin >> bool_init;
		d[i].car_avaliability = (bool_init == 1) ? true : false;

		cout << "������� ������ �� ������� �����: " << endl;
		cin >> bool_init;
		d[i].payment_avaliability = (bool_init == 1) ? true : false;
		system("cls");
	}

	ofstream out;
	out.open("../base.txt");

	if (out.is_open()) {
		cout << size << endl;
		out << size << endl;
	}

	for (int i = 0; i < size; i++) {
		if (out.is_open())
		{
			//����� ����� �� �����������
			out << d[i].place_number << endl;

			//��� ��������� ����������
			out << d[i].full_name.name << " ";
			out << d[i].full_name.surname << " ";
			out << d[i].full_name.partonimyc << endl;

			//����� ����������
			out << d[i].car_model << endl;

			//������� � ������� ���������� �� �������
			out << d[i].car_avaliability << endl;

			//������� �� ������ �� ������� �����
			out << d[i].payment_avaliability << endl;
		}
	}

	out.close();

	delete[] d;

	cout << "������ ������� ���������!" << endl;
}

void deleteByNumber(Data* (&d), int& n) {
	int elem = 0;
	cout << "������� ����� ������ ��� ��������: ";
	cin >> elem;
	int newSize = 0;

	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//����������� �������������
			//reading >> n;

			//����� ����� �� �����������
			reading >> d[i].place_number;

			//��� ��������� ����������
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//����� ����������
			reading >> d[i].car_model;

			//������� � ������� ���������� �� �������
			reading >> d[i].car_avaliability;

			//������� �� ������ �� ������� �����
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();

	newSize = n;

	for (int i = 0; i < newSize; i++) {
		if (d[i].place_number == elem) {
			cout << "������� ������!" << endl;
			newSize--; // ��������� ����������
			for (int j = i; j < newSize; j++) {
				d[j] = d[j + 1];
			}
			i--;

			ofstream out;
			out.open("../base.txt");

			if (out.is_open()) {
				out << newSize << endl;
			}

			for (int i = 0; i < newSize; i++) {
				if (out.is_open())
				{
					//����� ����� �� �����������
					out << d[i].place_number << endl;

					//��� ��������� ����������
					out << d[i].full_name.name << " ";
					out << d[i].full_name.surname << " ";
					out << d[i].full_name.partonimyc << endl;

					//����� ����������
					out << d[i].car_model << endl;

					//������� � ������� ���������� �� �������
					out << d[i].car_avaliability << endl;

					//������� �� ������ �� ������� �����
					out << d[i].payment_avaliability << endl;
				}
			}

			out.close();
		}
	}

	delete[] d;

	system("pause");
}

void editByNumber(Data* (&d), int& n) {
	int elem = 0;
	int bool_init;
	cout << "������� ����� ������ ��� ���������: ";
	cin >> elem;

	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//����������� �������������
			//reading >> n;

			//����� ����� �� �����������
			reading >> d[i].place_number;

			//��� ��������� ����������
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//����� ����������
			reading >> d[i].car_model;

			//������� � ������� ���������� �� �������
			reading >> d[i].car_avaliability;

			//������� �� ������ �� ������� �����
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();

	for (int i = 0; i < n; i++) {
		if (d[i].place_number == elem) {
			cout << "������� ������!" << endl;
			cout << "������������ " << i + 1 << endl;

			cout << "������� ����� �����: " << endl;
			cin >> d[i].place_number;


			cout << "������� ���: " << endl;
			cin >> d[i].full_name.name;
			cout << "������� �������: " << endl;
			cin >> d[i].full_name.surname;
			cout << "������� ��������: " << endl;
			cin >> d[i].full_name.partonimyc;


			cout << "������� ����� ����������: " << endl;
			cin >> d[i].car_model;

			cout << "������� ���������� �� �������: " << endl;
			cin >> bool_init;
			d[i].car_avaliability = (bool_init == 1) ? true : false;

			cout << "������� ������ �� ������� �����: " << endl;
			cin >> bool_init;
			d[i].payment_avaliability = (bool_init == 1) ? true : false;
			system("cls");
		}
	}


	ofstream out;
	out.open("../base.txt");

	if (out.is_open()) {
		out << n << endl;
	}

	for (int i = 0; i < n; i++) {
		if (out.is_open())
		{
			//����� ����� �� �����������
			out << d[i].place_number << endl;

			//��� ��������� ����������
			out << d[i].full_name.name << " ";
			out << d[i].full_name.surname << " ";
			out << d[i].full_name.partonimyc << endl;

			//����� ����������
			out << d[i].car_model << endl;

			//������� � ������� ���������� �� �������
			out << d[i].car_avaliability << endl;

			//������� �� ������ �� ������� �����
			out << d[i].payment_avaliability << endl;
		}
	}

	out.close();

	cout << "������ ������� �������� � ����!" << endl;

	delete[] d;

	system("pause");
}