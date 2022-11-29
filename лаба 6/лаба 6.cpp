#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include"FullName.h"
#include"Student.h"
#include"functions.h"
#include"Keys.h"


const std::vector<std::string> main_menu= { "Выход", "Добавить студента", "Просмотреть данные студента", 
    "Проставить отметки", "Вывести таблицу с оценками", "Сортировать список студентов" };
const std::vector<std::string> conformation_menu = { "Да", "Нет"};
const std::string LIST_FILE = "List.txt";
const std::string MAP_FILE = "Map.txt";


void show_meny(std::vector<std::string> meny, int num)
{
    for (int i = 0; i < meny.size(); i++)
    {
        if (i == num)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 << 4 | 0);
            std::cout << meny[i] << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else
        {
            std::cout << meny[i] << std::endl;
        }
    }
}
template <typename T>
void process_keys(Keys& keys, int& num, std::vector<T> vect)
{
    int a;
    while (true)
    {
        a = int(_getch());
        if (a == 72)
        {
            if (num - 1 > -1)
            {
                keys.set_top(true);
                num--;
                break;
            }
        }
        else if (a == 80)
        {
            if (num != vect.size() - 1)
            {
                keys.set_bot(true);
                num++;
                break;
            }
        }
        else if (a == 13)
        {
            keys.set_ent(true);
            break;
        }
    }
}

template<typename T>
void _swap(T& a, T& b) {
    T tmp = a;
    a = b;  
    b = tmp; 
}
int choose(std::map<FullName, int> mas)
{
    std::vector<std::string> str_mas;
    std::map<FullName, int>::iterator it = mas.begin();
    for (; it != mas.end(); *it++)
    {
        str_mas.push_back(FullName(it->first).GetFIO());
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        keys.all_false();
        system("cls");
        std::cout << "Выберите нужный объект" << std::endl;
        show_meny(str_mas, switcher);
        process_keys(keys, switcher, str_mas);
        if (keys.get_ent())
            break;
    }
    return switcher;
}
Student choose(std::list<Student> mas)
{
    std::vector<std::string> str_mas;
    std::list<Student>::iterator it = mas.begin();
    Student stud;
    for (; it != mas.end(); *it++)
    {
        str_mas.push_back(it->get_full_name().GetFIO());
    }
    int switcher = 0;
    Keys keys;
    while (true)
    {
        keys.all_false();
        system("cls");
        std::cout << "Выберите нужный объект" << std::endl;
        show_meny(str_mas, switcher);
        process_keys(keys, switcher, str_mas);
        if (keys.get_ent())
            break;
    }
    it = mas.begin();
    for (int i = 0; i < switcher; i++)
    {
        it++;
    }
    stud = *it;
    return stud;
}

Student add_Student()
{
    FullName fn;
    std::cout << "Введите фио студента" << std::endl;
    fn.SetFIO();
    Date date;
    std::cout << "Введите дату зачисления" << std::endl;
    date.SetDate();
    Student stud(fn, date);
    return stud;
}
void viev_Student(Student stud)
{
    std::cout << "ФИО: " << stud.get_full_name().GetFIO() << std::endl;
    std::cout << "Дата зачисления: " << stud.get_date_of_admission().GetDate() << std::endl;
}

Student find_by_fio(std::list<Student> list, FullName full_name)
{
    std::list<Student>::iterator i = list.begin();
    Student stud;
    for (; i != list.end(); i++)
    {
        if (i->get_full_name() == full_name)
        {
            stud = *i;
            return stud;
        }
    }
    throw;
}

void clear()
{
    std::ofstream f;
    f.open(LIST_FILE);
    f.close();
}


std::list<Student> list_from_file()
{
    Student stud;
    std::ifstream fin;
    FileException f;
    fin.open(LIST_FILE);
    if (!fin.is_open())
        throw f;
    fin.seekg(0, std::ios_base::end);
    int size = fin.tellg() / sizeof(Student);
    std::list<Student> lst;
    fin.clear();
    fin.seekg(0, std::ios_base::beg);
    while (fin.read((char*)&stud, sizeof(Student)))
    {
        lst.push_back(stud);
    }
    fin.close();
    return lst;
}
void list_to_file(std::list<Student> lst)
{
    Student stud;
    std::ofstream fout;
    FileException f;
    fout.open(LIST_FILE);
    if (!fout.is_open())
        throw f;
    for (std::list<Student>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        stud = *it;
        fout.write((char*)&stud, sizeof(Student));
    }
    fout.close();
}
std::map<FullName, int> map_from_file()
{
    FullName full_name;
    int mark = 0;
    std::ifstream fin;
    FileException f;
    fin.open(MAP_FILE);
    if (!fin.is_open())
        throw f;
    std::map<FullName, int> mp;
    while (fin.read((char*)&full_name, sizeof(FullName)))
    {
        fin.read((char*)&mark, sizeof(int));
        mp.insert(std::pair<FullName, int>(full_name, mark));
    }
    fin.close();
    return mp;
}
void map_to_file(std::map<FullName, int> mp)
{
    FullName full_name;
    int mark;
    std::ofstream fout;
    FileException f;
    fout.open(MAP_FILE);
    if (!fout.is_open())
        throw f;
    for (std::map<FullName, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        full_name = it->first;
        mark = it->second;
        fout.write((char*)&full_name, sizeof(FullName));
        fout.write((char*)&mark, sizeof(int));
    }
    fout.close();
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FullName full_name;
    int mark;
    int switcher = 0;
    Keys keys;
    std::list<Student> stud_list;
    Student stud;
    std::map<FullName, int> mark_list;
    std::map<FullName, int>::iterator it;
    try
    {
        stud_list = list_from_file();
        mark_list = map_from_file();
    }
    catch (...)
    {

    }
    while (true)
    {
        keys.all_false();
        system("cls");
        show_meny(main_menu, switcher);
        process_keys(keys, switcher, main_menu);
        std::cin.clear();
        if (keys.get_bot() || keys.get_top())
        {
            continue;
        }
        switch (switcher)
        {
        case 0:
            list_to_file(stud_list);
            map_to_file(mark_list);
            return 0;
        case 1:
            stud_list.push_back(add_Student());
            break;
        case 2:
            switcher = 0;
            while (true)
            {
                keys.all_false();
                system("cls");
                std::cout << "Вы хотите ввести ФИО студента сами?" << std::endl;
                show_meny(conformation_menu, switcher);
                process_keys(keys, switcher, conformation_menu);
                if (keys.get_ent())
                    break;
            }
            if (switcher == 0)
            {
                std::cout << "Введите ФИО нужного студента" << std::endl;
                full_name.SetFIO();
                stud = find_by_fio(stud_list, full_name);
            }
            else if (switcher == 1)
                stud = choose(stud_list);
            viev_Student(stud);
            break;
        case 3:
            switcher = 0;
            while (true)
            {
                keys.all_false();
                system("cls");
                std::cout << "Вы хотите ввести ФИО студента сами?" << std::endl;
                show_meny(conformation_menu, switcher);
                process_keys(keys, switcher, conformation_menu);
                if (keys.get_ent())
                    break;
            }
            if (switcher == 0)
            {
                std::cout << "Введите ФИО нужного студента" << std::endl;
                full_name.SetFIO();
                stud = find_by_fio(stud_list, full_name);
            }
            else if (switcher == 1)
                stud = choose(stud_list);
            std::cout << "Введите оценку выбранного студента" << std::endl;
            mark = input_int();
            try
            {
                mark_list[stud.get_full_name()] = mark;
            }
            catch (...)
            {
                full_name = stud.get_full_name();
                mark_list.insert(std::pair<FullName, int>(full_name, mark));
            }
        case 4:
            for (it = mark_list.begin(); it != mark_list.end(); it++)
            {
                std::cout << it->first.GetFIO() << ": " << it->second << std::endl;
            }
            break;
        case 5:
            stud_list.sort();
            break;
        }
        std::cin.clear();
        std::cin.ignore();
        wait();
    }
 
}

