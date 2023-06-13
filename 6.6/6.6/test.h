#pragma once

#include <iostream>

using namespace std;

class Data
{
public:
	//构造函数
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
	//拷贝构造函数
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
	//接下来就是运算符重载了
	Data& operator+=(int day);
	Data operator+(int day);
	Data& operator-=(int day);
	Data operator-(int day);
	int GetMonth(int year, int month);
	//日期减日期=天数
	int operator-(Data& d);


private:
	int _year;
	int _month;
	int _day;
};