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
//Ӧ����дGetMonth����
int Data::GetMonth(int year, int month)
{
	int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	return Month[month];
}
Data& Data::operator+=(int day)//���ڼ�������
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
Data Data::operator+(int day)//���ڱ����ǲ����,������Ҫ����һ����ʱ����
{
	Data tmp(*this);
	tmp += day;
	return tmp;
}

Data& Data::operator-=(int day)//���ڼ�һ������
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
Data Data::operator-(int day)//���ڱ����ı䣬��Ҫ����һ����ʱ����
{
	Data tmp(*this);
	tmp -= day;
	return tmp;
}
int Data::operator-(Data& d)
{
	Data max = *this;//Ĭ��*this���ڸ���Щ
	Data min = d;
	int flag = 1;//����һ����ǩ
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
