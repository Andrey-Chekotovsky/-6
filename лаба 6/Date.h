#pragma once
#include <string>
#include <iostream>
#include "Exeptions.h"
#include "functions.h"

class Date
{
private:
	int day, month, year;
	int Define_Month(int month, int year);
public:
	Date();

	Date(std::string date);

	void operator =(const Date& other);
	bool operator ==(const Date& other);
	bool operator !=(const Date& other);
	bool operator < (const Date& other);
	bool operator > (const Date& other);

	int SetDate();
	std::string GetDate();
};

