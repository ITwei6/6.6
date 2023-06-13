#include "test.h"

int main()
{
	Data d1(2023, 6, 6);
//	d1 -= 31;
	Data d2(2023, 6, 26);
	cout << (d2 - d1) << endl;
	d1.Print();
}