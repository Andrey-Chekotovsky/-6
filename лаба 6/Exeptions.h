#pragma once
#include <exception>
#include <string>

class DateTimeExeption : public std::exception
{
public:
	static std::string what()
	{
		return "Введены невозможные значения";
	}
};

class AddException : public std::exception
{
public:
	static std::string what()
	{
		return "Объект не может быть добавлен";
	}
};
class DeleteException : public std::exception
{
public:
	static std::string what()
	{
		return "Объект не может быть добавлен";
	}
};
class FileException : public std::exception
{
public:
	static std::string what()
	{
		return "Операция отменена: ошибка открытия файла";
	}
};
class FindException : public std::exception
{
public:
	static std::string what()
	{
		return "Операция отменена: элемента с заданными элементыми не сщуествует";
	}
};
