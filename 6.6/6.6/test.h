#pragma once

#include <iostream>

using namespace std;

class Data
{
public:
	//���캯��
	Data(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//�������캯��
	Data(const Data& d1)
	{
		_year = d1._year;
		_month = d1._month;
		_day = d1._day;
	}
	bool operator<(Data& d);
	bool operator==(Data& d);
	bool operator!=(Data& d);
	Data& operator++();
	Data operator++(int);
	//���������������������
	Data& operator+=(int day);
	Data operator+(int day);
	Data& operator-=(int day);
	Data operator-(int day);
	int GetMonth(int year, int month);
	//���ڼ�����=����
	int operator-(Data& d);


private:
	int _year;
	int _month;
	int _day;
};