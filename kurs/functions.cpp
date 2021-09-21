#include "functions.h";
using namespace std;

void DataEntry(Data* (&d), int& n) {
	cout << "Введите колличество пользователей для добавления: ";
	cin >> n;
	int bool_init;
	int count = 0;
	d = new Data[n];
	system("cls");
	for (int i = 0; i < n; i++) {
		count++;
		cout << "Пользователь " << count << endl;

		cout << "Введите номер места: " << endl;
		cin >> d[i].place_number;


		cout << "Введите имя: " << endl;
		cin >> d[i].full_name.name;
		cout << "Введите фамилию: " << endl;
		cin >> d[i].full_name.surname;
		cout << "Введите отчество: " << endl;
		cin >> d[i].full_name.partonimyc;


		cout << "Введите марку автомобиля: " << endl;
		cin >> d[i].car_model;

		cout << "Наличие автомобиля на стоянке: " << endl;
		cin >> bool_init;
		d[i].car_avaliability = (bool_init == 1) ? true : false;

		cout << "Наличие оплаты за текущий месяц: " << endl;
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
			//номер места на автостоянке
			out << d[i].place_number << endl;

			//ФИО владельца автомобиля
			out << d[i].full_name.name << " ";
			out << d[i].full_name.surname << " ";
			out << d[i].full_name.partonimyc << endl;

			//марка автомобиля
			out << d[i].car_model << endl;

			//отметка о наличии автомобиля на стоянке
			out << d[i].car_avaliability << endl;

			//отметка об оплате за текущий месяц
			out << d[i].payment_avaliability << endl;
		}
	}

	out.close();

	cout << "Данные успешно записаны в файл!" << endl;

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
			//колличество пользователей
			//reading >> n;

			//номер места на автостоянке
			reading >> d[i].place_number;

			//ФИО владельца автомобиля
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//марка автомобиля
			reading >> d[i].car_model;

			//отметка о наличии автомобиля на стоянке
			reading >> d[i].car_avaliability;

			//отметка об оплате за текущий месяц
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
	}

	reading.close();

	int count = 1;
	for (int i = 0; i < n; i++) {

		cout << "Номер пользователя: " << count << endl;

		//номер места на автостоянке
		cout << "номер места на автостоянке:" << endl;
		cout << d[i].place_number << endl;

		//ФИО владельца автомобиля
		cout << "ФИО владельца автомобиля:" << endl;
		cout << d[i].full_name.name << " ";
		cout << d[i].full_name.surname << " ";
		cout << d[i].full_name.partonimyc << endl;

		//марка автомобиля
		cout << "марка автомобиля:" << endl;
		cout << d[i].car_model << endl;


		//отметка о наличии автомобиля на стоянке
		cout << "отметка о наличии автомобиля на стоянке:" << endl;
		cout << d[i].car_avaliability << endl;

		//отметка об оплате за текущий месяц
		cout << "отметка об оплате за текущий месяц:" << endl;
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
			//колличество пользователей
			//reading >> n;


			//номер места на автостоянке
			reading >> d[i].place_number;

			//ФИО владельца автомобиля
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//марка автомобиля
			reading >> d[i].car_model;

			//отметка о наличии автомобиля на стоянке
			reading >> d[i].car_avaliability;

			//отметка об оплате за текущий месяц
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
	}

	reading.close();

	cout << "Номера свободных стоянок на данный момент: " << endl;

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
			//колличество пользователей
			//reading >> n;

			//номер места на автостоянке
			reading >> d[i].place_number;

			//ФИО владельца автомобиля
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//марка автомобиля
			reading >> d[i].car_model;

			//отметка о наличии автомобиля на стоянке
			reading >> d[i].car_avaliability;

			//отметка об оплате за текущий месяц
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
	}

	reading.close();

	for (int i = 0; i < n; i++) {
		if (d[i].payment_avaliability == 0) {
			cout << "Пользователь стоянки под номером: " << d[i].place_number << endl;

			cout << "ФИО: ";
			cout << d[i].full_name.name <<  " " << d[i].full_name.surname << " " << d[i].full_name.partonimyc << " " << endl;

			cout << "Марка автомобиля: ";
			cout << d[i].car_model << endl;
		}
	}
}

void addInfo(Data* (&d), int& n) {

	int count = 0;
	int bool_init;
	int arrCount = 0;
	int size = 0;

	cout << "Введите колличество полей для добавления: ";
	cin >> arrCount;
	//cout << arrCount << endl;
	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;
		size = n + arrCount;

		d = new Data[size];

		for (int i = 0; i < n; i++) {
			//колличество пользователей
			//reading >> n;

			//номер места на автостоянке
			reading >> d[i].place_number;

			//ФИО владельца автомобиля
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//марка автомобиля
			reading >> d[i].car_model;

			//отметка о наличии автомобиля на стоянке
			reading >> d[i].car_avaliability;

			//отметка об оплате за текущий месяц
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
	}

	reading.close();

	for (int i = n; i < size; i++) {
		cout << "Пользователь " << i + 1 << endl;

		cout << "Введите номер места: " << endl;
		cin >> d[i].place_number;


		cout << "Введите имя: " << endl;
		cin >> d[i].full_name.name;
		cout << "Введите фамилию: " << endl;
		cin >> d[i].full_name.surname;
		cout << "Введите отчество: " << endl;
		cin >> d[i].full_name.partonimyc;


		cout << "Введите марку автомобиля: " << endl;
		cin >> d[i].car_model;

		cout << "Наличие автомобиля на стоянке: " << endl;
		cin >> bool_init;
		d[i].car_avaliability = (bool_init == 1) ? true : false;

		cout << "Наличие оплаты за текущий месяц: " << endl;
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
			//номер места на автостоянке
			out << d[i].place_number << endl;

			//ФИО владельца автомобиля
			out << d[i].full_name.name << " ";
			out << d[i].full_name.surname << " ";
			out << d[i].full_name.partonimyc << endl;

			//марка автомобиля
			out << d[i].car_model << endl;

			//отметка о наличии автомобиля на стоянке
			out << d[i].car_avaliability << endl;

			//отметка об оплате за текущий месяц
			out << d[i].payment_avaliability << endl;
		}
	}

	out.close();

	delete[] d;

	cout << "Данные успешно добавлены!" << endl;
}

void deleteByNumber(Data* (&d), int& n) {
	int elem = 0;
	cout << "Введите номер записи для удаления: ";
	cin >> elem;
	int newSize = 0;

	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//колличество пользователей
			//reading >> n;

			//номер места на автостоянке
			reading >> d[i].place_number;

			//ФИО владельца автомобиля
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//марка автомобиля
			reading >> d[i].car_model;

			//отметка о наличии автомобиля на стоянке
			reading >> d[i].car_avaliability;

			//отметка об оплате за текущий месяц
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
	}

	reading.close();

	newSize = n;

	for (int i = 0; i < newSize; i++) {
		if (d[i].place_number == elem) {
			cout << "Элемент найден!" << endl;
			newSize--; // уменьшаем количество
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
					//номер места на автостоянке
					out << d[i].place_number << endl;

					//ФИО владельца автомобиля
					out << d[i].full_name.name << " ";
					out << d[i].full_name.surname << " ";
					out << d[i].full_name.partonimyc << endl;

					//марка автомобиля
					out << d[i].car_model << endl;

					//отметка о наличии автомобиля на стоянке
					out << d[i].car_avaliability << endl;

					//отметка об оплате за текущий месяц
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
	cout << "Введите номер записи для изменения: ";
	cin >> elem;

	ifstream reading("../base.txt");
	string line;

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//колличество пользователей
			//reading >> n;

			//номер места на автостоянке
			reading >> d[i].place_number;

			//ФИО владельца автомобиля
			reading >> d[i].full_name.name;
			reading >> d[i].full_name.surname;
			reading >> d[i].full_name.partonimyc;

			//марка автомобиля
			reading >> d[i].car_model;

			//отметка о наличии автомобиля на стоянке
			reading >> d[i].car_avaliability;

			//отметка об оплате за текущий месяц
			reading >> d[i].payment_avaliability;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
	}

	reading.close();

	for (int i = 0; i < n; i++) {
		if (d[i].place_number == elem) {
			cout << "Элемент найден!" << endl;
			cout << "Пользователь " << i + 1 << endl;

			cout << "Введите номер места: " << endl;
			cin >> d[i].place_number;


			cout << "Введите имя: " << endl;
			cin >> d[i].full_name.name;
			cout << "Введите фамилию: " << endl;
			cin >> d[i].full_name.surname;
			cout << "Введите отчество: " << endl;
			cin >> d[i].full_name.partonimyc;


			cout << "Введите марку автомобиля: " << endl;
			cin >> d[i].car_model;

			cout << "Наличие автомобиля на стоянке: " << endl;
			cin >> bool_init;
			d[i].car_avaliability = (bool_init == 1) ? true : false;

			cout << "Наличие оплаты за текущий месяц: " << endl;
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
			//номер места на автостоянке
			out << d[i].place_number << endl;

			//ФИО владельца автомобиля
			out << d[i].full_name.name << " ";
			out << d[i].full_name.surname << " ";
			out << d[i].full_name.partonimyc << endl;

			//марка автомобиля
			out << d[i].car_model << endl;

			//отметка о наличии автомобиля на стоянке
			out << d[i].car_avaliability << endl;

			//отметка об оплате за текущий месяц
			out << d[i].payment_avaliability << endl;
		}
	}

	out.close();

	cout << "Данные успешно записаны в файл!" << endl;

	delete[] d;

	system("pause");
}