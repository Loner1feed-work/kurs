#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*
	������:
	!. ����� ����� �� �����������
	2. ��� ���������
	3. ����� ����������
	4. ������� � ������� ����������
	5. ������� �� ������ �� ������� �����
*/


// ��������� ���
struct Initial {
	string name,
		surname,
		partonimyc;
};


// ��������� ������ 
struct Data {
	int place_number;
	Initial full_name;
	string car_model;
	bool car_avaliability;
	bool payment_avaliability;
};


//��������� �������
void DataEntry(Data* (&d), int& n);
void ReadingData(Data* (&d), int& n);
void AvaliablePlaces(Data* (&d), int& n);
void NonPaidUsers(Data* (&d), int& n);
void addInfo(Data* (&d), int& n);
void deleteByNumber(Data* (&d), int& n);
void editByNumber(Data* (&d), int& n);