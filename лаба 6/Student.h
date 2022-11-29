#pragma once
#include"Date.h"
#include"FullName.h"


class Student
{
private:
	FullName full_name;
	Date date_of_admission;
public:
	Student() {}
	Student(FullName full_name, Date date_of_admission)
	{
		this->full_name = full_name;
		this->date_of_admission = date_of_admission;
	}
	Student(const Student& other)
	{
		this->full_name = other.full_name;
		this->date_of_admission = other.date_of_admission;
	}
	void set_full_name(FullName  full_name)
	{
		this->full_name = full_name;
	}
	FullName get_full_name()
	{
		return this->full_name;
	}
	void set_date_of_admission(Date  date_of_admission)
	{
		this->date_of_admission = date_of_admission;
	}
	Date get_date_of_admission()
	{
		return this->date_of_admission;
	}
	void operator =(const Student& other);
	bool operator <(Student& other)
	{
		if (this->full_name < other.full_name)
			return true;
		else
			return false;
	}
	bool operator >(Student& other)
	{
		if (this->full_name > other.full_name)
			return true;
		else
			return false;
	}
	bool operator ==(Student& other)
	{
		if (this->full_name == other.full_name)
			return true;
		else
			return false;
	}
};

