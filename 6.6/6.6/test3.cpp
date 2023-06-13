#include "test.h"

bool Data::operator<(Data& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	
	return false;

}
bool Data::operator==(Data& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Data::operator!=(Data& d)
{
	return !(*this == d);
}
Data& Data::operator++()
{
	*this += 1;
	return *this;
}
Data Data::operator++(int)
{
	Data tmp(*this);
	*this += 1;
	return tmp;
}
//应该先写GetMonth函数
int Data::GetMonth(int year, int month)
{
	int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	return Month[month];
}
Data& Data::operator+=(int day)//日期加上天数
{
	_day += day;
	while (_day > GetMonth(_year, _month))
	{
		++_month;
		_day -= GetMonth(_year, _month);
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}
Data Data::operator+(int day)//日期本身是不变的,所以需要拷贝一个临时对象
{
	Data tmp(*this);
	tmp += day;
	return tmp;
}

Data& Data::operator-=(int day)//日期减一个天数
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		_day += GetMonth(_year, _month);
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

	}
	return *this;
}
Data Data::operator-(int day)//日期本身不改变，需要拷贝一个临时变量
{
	Data tmp(*this);
	tmp -= day;
	return tmp;
}
int Data::operator-(Data& d)
{
	Data max = *this;//默认*this日期更大些
	Data min = d;
	int flag = 1;//定义一个标签
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}
