#include "Student.h"


void Student::operator =(const Student& other)
{
	this->full_name = other.full_name;
	this->date_of_admission = other.date_of_admission;
}