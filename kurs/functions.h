#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*
	Данные:
	!. Номер места на автостоянке
	2. ФИО владельца
	3. марка автомобиля
	4. отметка о наличии автомобиля
	5. отметка об оплате за текущий месяц
*/


// структура ФИО
struct Initial {
	string name,
		surname,
		partonimyc;
};


// структура данных 
struct Data {
	int place_number;
	Initial full_name;
	string car_model;
	bool car_avaliability;
	bool payment_avaliability;
};


//прототипы функций
void DataEntry(Data* (&d), int& n);
void ReadingData(Data* (&d), int& n);
void AvaliablePlaces(Data* (&d), int& n);
void NonPaidUsers(Data* (&d), int& n);
void addInfo(Data* (&d), int& n);
void deleteByNumber(Data* (&d), int& n);
void editByNumber(Data* (&d), int& n);