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
    cout << "������� ��� ����������." << endl;
    string name, surname, midname;
    cout << "���: ";
    cin >> name;
    newSoldier.set_name(name);
    cout << "\n�������: ";
    cin >> surname;
    newSoldier.set_surname(surname);
    cout << "\n��������: ";
    cin >> midname;
    newSoldier.set_midname(midname);
    cout << "\n������� ���� ��������. " << endl;
    int day, mounth, year;
    cout << "��� ��������: ";
    cin >> year;
    newSoldier.set_year(year);
    cout << "\n�����: ";
    cin >> mounth;
    newSoldier.set_mounth(mounth);
    cout << "\n����: ";
    cin >> day;
    newSoldier.set_day(day);
    cout << "\n������ �� ������ ���������? \n 1 - �� \n 0 - ���" << endl;
    int choice;
    cin >> choice;
    string education;
    string place_of_study;
    if (choice == 1)
    {
        cout << "������� ������� �����������." << endl;
        cin >> education;
        cout << "������� ����� �����." << endl;
        cin >> place_of_study;
        choice = 0;
    }
    else
    {
        choice = 0;
        cout << "��������� �������� ������ ������� ���������? \n 1 - ��\n 0 - ���" << endl;
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
    cout << "�������� �� ������ ���������? \n 1 - ��\n 0 - ���" << endl;
    cin >> choice;
    string job;
    if (choice == 1)
    {
        cout << "������� ����� ������" << endl;
        cin >> job;
        choice = 0;
    }
    else
    {
        job = "-";
    }
    newSoldier.set_job(job);
    cout << "������� ����� ����� � ���. �����." << endl;
    int HealthGraph;
    cin >> HealthGraph;
    newSoldier.set_HealthGraph(HealthGraph);
    cout << "��������� ����� � ������? \n 1 - ��\n 0 -���" << endl;
    bool status;
    cin >> status;
    newSoldier.set_Status(status);
    cout << name << " ��������?  \n 1 - ��\n 0 - ���" << endl;
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
            cout << "���: " << soldier_[i].get_name() << endl;
            cout << "�������: " << soldier_[i].get_surname() << endl;
            cout << "��������: " << soldier_[i].get_midname() << endl;
            if (soldier_[i].get_mounth() < 10)
            {
                if (soldier_[i].get_day() < 10)
                {
                    cout << "���� ��������: 0" << soldier_[i].get_day() << ".0" << soldier_[i].get_mounth()
                        << "." << soldier_[i].get_year() << endl;
                }
                else
                {
                    cout << "���� ��������: " << soldier_[i].get_day() << ".0" << soldier_[i].get_mounth()
                        << "." << soldier_[i].get_year() << endl;
                }
            }
            else
            {
                cout << "���� ��������: " << soldier_[i].get_day() << "." << soldier_[i].get_mounth()
                    << "." << soldier_[i].get_year() << endl;
            }
            cout << "�����������: " << soldier_[i].get_education() << endl;
            cout << "����� �����: " << soldier_[i].get_place_of_study() << endl;
            cout << "����� ������: " << soldier_[i].get_job() << endl;
            cout << "����� ������ ���. �����: " << soldier_[i].get_HealthGraph() << endl;
            cout << "������� ��������: ";
            if (soldier_[i].get_Status())
            {
                cout << "�����." << endl;
            }
            else
            {
                cout << "�� �����." << endl;
            }
            cout << "������: " << soldier_[i].get_rank() << endl;
            cout << "���������� � ������: ";
            if (soldier_[i].get_ServiceStatus())
            {
                cout << "������." << endl;
            }
            else
            {
                cout << "�� ������." << endl;
            }
            cout << "<================================>" << endl;
        }
    }
    else
    {
        cout << "������ ������ ����." << endl;
    }
    system("pause");
}

void SoldierBaseService::FindSoldier()
{
    int type_of_finding;

    cout << "������� ��� ������ �������. \n 1 - �� �����. \n 2 - �� �������. \n 3 - �� ��������." << endl;
    cin >> type_of_finding;

    string FIO;
    Soldier *soldier;

    cout << "���������� ����� �������." << endl;
    switch (type_of_finding)
    {
    case 1:
    {
        cout << "������� ��� �������." << endl;
        cin >> FIO;
        soldier = new Soldier(1, FIO, "", "");
        break;
    }
    case 2:
    {
        cout << "������� ������� �������." << endl;
        cin >> FIO;
        soldier = new Soldier(1, "", FIO, "");
        break;
    }
    case 3:
    {
        cout << "������� �������� �������." << endl;
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
        cout << "������ � ��������� ������� �� ������" << endl;
    }
    system("pause");
}

void SoldierBaseService::SortSoldier(int on_case)
{
    cout << "���������� ����������." << endl;
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
    cout << "������ ������� �� ������ ��������?" << endl;
    cout << ">> ";
    int index;
    cin >> index;
    index--;
    Soldier newSoldier;
    newSoldier = this->soldier_[index];
    int choice;
    cout << "\n������ �� �� �������� ���?\n 1 - ��\n 0 - ���" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        string name;
        cin >> name;
        newSoldier.set_name(name);
        choice = 0;
    }
    cout << "\n������ �� �� �������� �������?\n 1 - ��\n 0 - ���" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        string surname;
        cin >> surname;
        newSoldier.set_surname(surname);
        choice = 0;
    }
    cout << "\n������ �� �� �������� ��������?\n 1 - ��\n 0 - ���" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        string midname;
        cin >> midname;
        newSoldier.set_midname(midname);
        choice = 0;
    }
    cout << "\n������ �� �� �������� ���� ��������?\n 1 - �� \n 0 - ��� " << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 1)
    {
        int day, mounth, year;
        cout << "����: ";
        cin >> day;
        newSoldier.set_day(day);
        cout << "\n�����: ";
        cin >> mounth;
        newSoldier.set_mounth(mounth);
        cout << "\n���: ";
        cin >> year;
        newSoldier.set_year(year);
        choice = 0;
    }
    this->soldier_[index] = newSoldier;
    cout << "������ �� �� �������� ���������� �� ��� ����� �������? \n 1 - yes; \n 0 - no" << endl;
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
    cout << "������� ����� ����������, ���������� � ������ �������� �� ������ ��������." << endl;
    int index;
    cin >> index;
    index--;
    Soldier newSoldier;
    newSoldier = this->soldier_[index];
    bool ServiceStatus;
    cout << "�������, �������� ��������� � ����� ��� ���. \n1 - ��\n0 - ���" << endl;
    cin >> ServiceStatus;
    newSoldier.set_ServiceStatus(ServiceStatus);
    this->soldier_[index] = newSoldier;
    this->SaveData();
}

void SoldierBaseService::UpdateSoldierHealth()
{
    this->show();
    cout << "������� ����� �������, ���������� � ���. ����� �������� �� ������ ��������?" << endl;
    int index;
    cin >> index;
    index--;
    Soldier newSoldier;
    newSoldier = this->soldier_[index];
    cout << "������� ����� �����" << endl;
    int HealthGraph = 0;
    cin >> HealthGraph;
    newSoldier.set_HealthGraph(HealthGraph);
    this->soldier_[index] = newSoldier;
    this->SaveData();
}

void SoldierBaseService::ReadSoldierHealth()
{
    cout << "���. ����� ������ ���������� �� ������ ��������?" << endl;
    int index;
    cin >> index;
    index--;
    cout << "���������� ������ ���. ����� ����������..." << endl;
    cout << endl;
    cout << "���: " << soldier_[index].get_name() << endl;
    cout << "�������: " << soldier_[index].get_surname() << endl;
    cout << "��������: " << soldier_[index].get_midname() << endl;
    cout << "������ � �������: " << soldier_[index].get_HealthGraph() << endl;
    bool status = soldier_[index].get_Status();
    if (status)
    {
        cout << "��������� " << soldier_[index].get_surname() << " ����� � ������." << endl;
    }
    else
    {
        cout << "��������� " << soldier_[index].get_surname() << " �� ����� � ������." << endl;
    }
}


void SoldierBaseService::DeleteSoldier()
{
    this->show();
    int id_for_delete = 0;
    cout << "������� ����� �������, �������� ������ �������.";
    cin >> id_for_delete;
    id_for_delete--;
    cout << "\n���������� �������� ����������." << endl;
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