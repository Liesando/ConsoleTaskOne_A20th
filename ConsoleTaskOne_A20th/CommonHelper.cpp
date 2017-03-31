#include "CommonHelper.h"

void PrintError(string text, string title)
{
	cout << endl;
	cout << systemBegin << title << systemEnd << endl;
	cout << text << endl;
	cout << systemBegin << title << systemEnd << endl;
	cout << endl;
}

int Abs(int value)
{
	return value >= 0 ? value : -value;
}

int Random(int min, int max)
{
	return min + rand() % (Abs(max - min) + 1);
}