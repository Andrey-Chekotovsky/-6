#pragma once
#include <string>
#include <iostream>

class FullName
{
private:
	char Name[30], Surname[30], Patronymic[30];
public:
	FullName();
	FullName(std::string full_name);
	FullName(char name[30], char surname[30], char patronymic[30]);
	FullName(FullName const& fn);
	std::string GetFIO() const;
	void SetFIO();
	bool operator <(FullName const&  other) const;
	bool operator >(const FullName& other);
	void operator =(const FullName& other);
	bool operator ==(const FullName& other);
};

