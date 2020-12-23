#include <algorithm> 
#include <string>
#include <fstream>

#include"ClassSoldierBaseService.h"

using namespace std;

SoldierBaseService::SoldierBaseService()
{
    this->path_ = "soldier.txt";
    this->LoadData();
}

SoldierBaseService::~SoldierBaseService()
{
}

string SoldierBaseService::Split(string & s, string delimiter)
{
    size_t start_pos = 0, end_pos;
    string substr;
    if ((end_pos = s.find(delimiter, start_pos)) != string::npos)
    {
        substr = s.substr(start_pos, end_pos - start_pos);
        s = s.substr(end_pos - start_pos + 1, s.length());
    }
    return substr;
}

void SoldierBaseService::CreateSoldier()
{
    Soldier newSoldier;
    int ID;
    ID = this->soldier_.size() + 1;
    newSoldier.set_id(ID);
    cout << "Введите ФИО призывника." << endl;
    string name, surname, midname;
    cout << "Имя: ";
    cin >> name;
    newSoldier.set_name(name);
    cout << "\nФамилия: ";
    cin >> surname;
    newSoldier.set_surname(surname);
    cout << "\nОтчество: ";
    cin >> midname;
    newSoldier.set_midname(midname);
    cout << "\nВведите дату рождения. " << endl;
    int day, mounth, year;
    cout << "Год рождения: ";
    cin >> year;
    newSoldier.set_year(year);
    cout << "\nМесяц: ";
    cin >> mounth;
    newSoldier.set_mounth(mounth);
    cout << "\nДень: ";
    cin >> day;
    newSoldier.set_day(day);
    cout << "\nУчится ли сейчас призывник? \n 1 - Да \n 0 - Нет" << endl;
    int choice;
    cin >> choice;
    string education;
    string place_of_study;
    if (choice == 1)
    {
        cout << "Введите уровень образования." << endl;
        cin >> education;
        cout << "Введите место учёбы." << endl;
        cin >> place_of_study;
        choice = 0;
    }
    else
    {
        choice = 0;
        cout << "Призывник закончил высшее учебное заведение? \n 1 - да\n 0 - нет" << endl;
        cin >> choice;
        if (choice == 1)
        {
            education = "higher";
        }
        else
        {
            education = "middle";
        }
        place_of_study = "-";
    }
    newSoldier.set_education(education);
    newSoldier.set_place_of_study(place_of_study);
    cout << "Работает ли сейчас призывник? \n 1 - Да\n 0 - Нет" << endl;
    cin >> choice;
    string job;
    if (choice == 1)
    {
        cout << "Введите место работы" << endl;
        cin >> job;
        choice = 0;
    }
    else
    {
        job = "-";
    }
    newSoldier.set_job(job);
    cout << "Введите номер графы в мед. карте." << endl;
    int HealthGraph;
    cin >> HealthGraph;
    newSoldier.set_HealthGraph(HealthGraph);
    cout << "Призывник годен к службе? \n 1 - Да\n 0 -Нет" << endl;
    bool status;
    cin >> status;
    newSoldier.set_Status(status);
    cout << name << " отслужил?  \n 1 - Да\n 0 - Нет" << endl;
    string rank;
    bool ServiceStatus;
    cin >> choice;
    if (choice == 1)
    {
        rank = "soldier";
        ServiceStatus = true;
    }
    else
    {
        rank = "inductee";
        ServiceStatus = false;
    }
    newSoldier.set_rank(rank);
    newSoldier.set_ServiceStatus(ServiceStatus);
    this->soldier_.push_back(newSoldier);
    this->SaveData();
}

void SoldierBaseService::ReadSoldiers()
{
    for (auto i : this->soldier_) cout << i << endl;
}

void SoldierBaseService::show()
{
    if (!this->soldier_.empty()) {
        cout << "<================================>" << endl;
        for (int i = 0; i < this->soldier_.size(); i++)
        {
            cout << i + 1 << "." << endl;
            cout << "Имя: " << soldier_[i].get_name() << endl;
            cout << "Фамилия: " << soldier_[i].get_surname() << endl;
            cout << "Отчество: " << soldier_[i].get_midname() << endl;
            if (soldier_[i].get_mounth() < 10)
            {
                if (soldier_[i].get_day() < 10)
                {
                    cout << "Дата рождения: 0" << soldier_[i].get_day() << ".0" << soldier_[i].get_mounth()
                        << "." << soldier_[i].get_year() << endl;
                }
                else
                {
                    cout << "Дата рождения: " << soldier_[i].get_day() << ".0" << soldier_[i].get_mounth()
                        << "." << soldier_[i].get_year() << endl;
                }
            }
            else
            {
                cout << "Дата рождения: " << soldier_[i].get_day() << "." << soldier_[i].get_mounth()
                    << "." << soldier_[i].get_year() << endl;
            }
            cout << "Образование: " << soldier_[i].get_education() << endl;
            cout << "Место учёбы: " << soldier_[i].get_place_of_study() << endl;
            cout << "Место работы: " << soldier_[i].get_job() << endl;
            cout << "Номер ячейки мед. карты: " << soldier_[i].get_HealthGraph() << endl;
            cout << "Степень годности: ";
            if (soldier_[i].get_Status())
            {
                cout << "Годен." << endl;
            }
            else
            {
                cout << "Не годен." << endl;
            }
            cout << "Статус: " << soldier_[i].get_rank() << endl;
            cout << "Информация о службе: ";
            if (soldier_[i].get_ServiceStatus())
            {
                cout << "Служит." << endl;
            }
            else
            {
                cout << "Не служит." << endl;
            }
            cout << "<================================>" << endl;
        }
    }
    else
    {
        cout << "Список солдат пуст." << endl;
    }
    system("pause");
}

void SoldierBaseService::FindSoldier()
{
    int type_of_finding;

    cout << "Введите тип поиска солдата. \n 1 - По имени. \n 2 - по фамилии. \n 3 - по отчеству." << endl;
    cin >> type_of_finding;

    string FIO;
    Soldier *soldier;

    cout << "Происходит поиск солдата." << endl;
    switch (type_of_finding)
    {
    case 1:
    {
        cout << "Введите имя солдата." << endl;
        cin >> FIO;
        soldier = new Soldier(1, FIO, "", "");
        break;
    }
    case 2:
    {
        cout << "Введите фамилию солдата." << endl;
        cin >> FIO;
        soldier = new Soldier(1, "", FIO, "");
        break;
    }
    case 3:
    {
        cout << "Введите отчество солдата." << endl;
        cin >> FIO;
        soldier = new Soldier(1, "", "", FIO);
        break;
    }
    default:
    {
        soldier = new Soldier();
    }
    }
    bool finded = false;

    for (auto i : this->soldier_)
    {
        if (i == *soldier)
        {
            cout << i << endl;
            finded = true;
        }
    }
    if (!finded)
    {
        cout << "Солдат с заданными данными не найден" << endl;
    }
    system("pause");
}

void SoldierBaseService::SortSoldier(int on_case)
{
    cout << "Происходит сортировка." << endl;
    switch (on_case)
    {
    case 1:
    {
        sort(this->soldier_.begin(), this->soldier_.end(), [](Soldier& f, Soldier& s)
        {
            return(f.get_name() < s.get_name());
        });
        break;
    }
    case 2:
    {
        sort(this->soldier_.begin(), this->soldier_.end(), [](Soldier& f, Soldier& s)
        {
            return(f.get_surname() < s.get_surname());
        });
    }
    case 3:
    {
        sort(this->soldier_.begin(), this->soldier_.end(), [](Soldier&f, Soldier& s)
        {
            return(f.get_year() < s.get_year() && f.get_mounth() < s.get_mounth() && f.get_day() < s.get_day());
        });
    }
    default:
    {
        sort(this->soldier_.begin(), this->soldier_.end(), [](Soldier& f, Soldier& s)
        {
            return (f.get_id() < s.get_id());
        });
        break;
    }
    }
    this->show();
}

void  SoldierBaseService::UpdateSoldier()
{
    this->show();
    cout << "Какого солдата вы хотите изменить?" << endl;
    cout << ">> ";
    int index;
    cin >> index;
    index--;
    Soldier newSoldier;
    newSoldier = this->soldier_[index];
    int choice;
    cout << "\nХотите ли вы изменить имя?\n 1 - да\n 0 - нет" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        string name;
        cin >> name;
        newSoldier.set_name(name);
        choice = 0;
    }
    cout << "\nХотите ли вы изменить фамилию?\n 1 - да\n 0 - нет" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        string surname;
        cin >> surname;
        newSoldier.set_surname(surname);
        choice = 0;
    }
    cout << "\nХотите ли вы изменить отчество?\n 1 - да\n 0 - нет" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        string midname;
        cin >> midname;
        newSoldier.set_midname(midname);
        choice = 0;
    }
    cout << "\nХотите ли вы изменить дату рождения?\n 1 - да \n 0 - нет " << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        int day, mounth, year;
        cout << "День: ";
        cin >> day;
        newSoldier.set_day(day);
        cout << "\nМесяц: ";
        cin >> mounth;
        newSoldier.set_mounth(mounth);
        cout << "\nГод: ";
        cin >> year;
        newSoldier.set_year(year);
        choice = 0;
    }
    this->soldier_[index] = newSoldier;
    cout << "Хотите ли вы изменить информацию об ещё одном солдате? \n 1 - yes; \n 0 - no" << endl;
    cin >> choice;
    if (choice == 1)
    {
        UpdateSoldier();
    }
    else
    {
        this->SaveData();
        return;
    }
}

void SoldierBaseService::UpdateSoldierService()
{
    this->show();
    cout << "Введите номер призывника, информацию о службе которого вы хотите изменить." << endl;
    int index;
    cin >> index;
    index--;
    Soldier newSoldier;
    newSoldier = this->soldier_[index];
    bool ServiceStatus;
    cout << "Укажите, отслужил призывник в армии или нет. \n1 - да\n0 - нет" << endl;
    cin >> ServiceStatus;
    newSoldier.set_ServiceStatus(ServiceStatus);
    this->soldier_[index] = newSoldier;
    this->SaveData();
}

void SoldierBaseService::UpdateSoldierHealth()
{
    this->show();
    cout << "Введите номер солдата, информацию о мед. карте которого вы хотите изменить?" << endl;
    int index;
    cin >> index;
    index--;
    Soldier newSoldier;
    newSoldier = this->soldier_[index];
    cout << "Введите номер графы" << endl;
    int HealthGraph = 0;
    cin >> HealthGraph;
    newSoldier.set_HealthGraph(HealthGraph);
    this->soldier_[index] = newSoldier;
    this->SaveData();
}

void SoldierBaseService::ReadSoldierHealth()
{
    cout << "Мед. карту какого призывника вы хотите получить?" << endl;
    int index;
    cin >> index;
    index--;
    cout << "Происходит чтение мед. карты Призывника..." << endl;
    cout << endl;
    cout << "Имя: " << soldier_[index].get_name() << endl;
    cout << "Фамилия: " << soldier_[index].get_surname() << endl;
    cout << "Отчество: " << soldier_[index].get_midname() << endl;
    cout << "Ячейка в таблице: " << soldier_[index].get_HealthGraph() << endl;
    bool status = soldier_[index].get_Status();
    if (status)
    {
        cout << "Призывник " << soldier_[index].get_surname() << " годен к службе." << endl;
    }
    else
    {
        cout << "Призывник " << soldier_[index].get_surname() << " не годен к службе." << endl;
    }
}


void SoldierBaseService::DeleteSoldier()
{
    this->show();
    int id_for_delete = 0;
    cout << "Введите номер солдата, которого хотите удалить.";
    cin >> id_for_delete;
    id_for_delete--;
    cout << "\nПроисходит удаление призывника." << endl;
    soldier_.erase(soldier_.begin() + id_for_delete);
    this->SaveData();
}


int SoldierBaseService::LoadData()
{
    ifstream fin;
    fin.open(this->path_);
    if (!fin.is_open())
    {
        return 0;
    }
    else
    {
        string datafromfile;
        string delimiter = "/";
        string delimiter1 = ".";

        getline(fin, datafromfile);

        while (!fin.eof())
        {
            getline(fin, datafromfile);
            string name, surname, midname;
            string job, education, place_of_study, rank;
            string stringID, stringHealthGraph, stringStatus, stringServiceStatus;
            string stringDay, stringMounth, stringYear;
            int day, mounth, year;
            int ID, HealthGraph;
            bool Status, ServiceStatus;
            try
            {
                stringID = Split(datafromfile, delimiter);
                ID = stoi(stringID);
                name = Split(datafromfile, delimiter);
                surname = Split(datafromfile, delimiter);
                midname = Split(datafromfile, delimiter);
                stringDay = Split(datafromfile, delimiter1);
                day = stoi(stringDay);
                stringMounth = Split(datafromfile, delimiter1);
                mounth = stoi(stringMounth);
                stringYear = Split(datafromfile, delimiter);
                year = stoi(stringYear);
                education = Split(datafromfile, delimiter);
                place_of_study = Split(datafromfile, delimiter);
                job = Split(datafromfile, delimiter);
                stringHealthGraph = Split(datafromfile, delimiter);
                HealthGraph = stoi(stringHealthGraph);
                stringStatus = Split(datafromfile, delimiter);
                Status = stoi(stringStatus);
                rank = Split(datafromfile, delimiter);
                stringServiceStatus = Split(datafromfile, delimiter);
                ServiceStatus = stoi(stringServiceStatus);
                this->soldier_.push_back(Soldier(ID, name, surname, midname, day, mounth, year, job, education, place_of_study, HealthGraph, Status, ServiceStatus, rank));
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }
    fin.close();
    return 1;
}

int SoldierBaseService::SaveData()
{
    ofstream fout;
    fout.open(this->path_);
    if (!fout.is_open())
    {
        return 0;
    }
    else
    {
        string datatofile;
        string delimiter = "/";

        fout << "Id/Name/Midname/Surname/Day.of.Birth/Education/place_of_study/Job/HealthGraph/Status/Rank/ServiceStatus";
        for (int i = 0; i < this->soldier_.size(); i++)
        {
            fout << endl << this->soldier_[i].get_id() << "/" << this->soldier_[i].get_name() << "/"
                << this->soldier_[i].get_midname() << "/" << this->soldier_[i].get_surname() << "/"
                << this->soldier_[i].get_day() << "." << this->soldier_[i].get_mounth() << "."
                << this->soldier_[i].get_year() << "/" << this->soldier_[i].get_education() << "/"
                << this->soldier_[i].get_place_of_study() << "/" << this->soldier_[i].get_job() << "/"
                << this->soldier_[i].get_HealthGraph() << "/" << this->soldier_[i].get_Status() << "/"
                << this->soldier_[i].get_rank() << "/" << this->soldier_[i].get_ServiceStatus() << "/";
        }
    }
    fout.close();
    return 1;
}