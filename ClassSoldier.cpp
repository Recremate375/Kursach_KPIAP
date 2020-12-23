#include<vector>

#include"ClassSoldier.h"

Soldier::Soldier()
{
    this->ID_ = 0;
    this->name_ = " ";
    this->surname_ = " ";
    this->midname_ = " ";
    this->education_ = " ";
    this->place_of_study_ = " ";
    this->HealthGraph_ = 0;
    this->job_ = " ";
    this->Status_ = 0;
    this->Servicestatus_ = 0;
    this->rank_ = " ";
}

Soldier::Soldier(int ID, string name, string surname, string midname, int day, int mounth, int year, string job, string education, string place_of_study, int HealthGraph, bool Status, bool ServiceStatus, string rank)
{
    this->ID_ = ID;
    this->name_ = name;
    this->surname_ = surname;
    this->midname_ = midname;
    this->day_ = day;
    this->mounth_ = mounth;
    this->year_ = year;
    this->job_ = job;
    this->education_ = education;
    this->place_of_study_ = place_of_study;
    this->HealthGraph_ = HealthGraph;
    this->Status_ = Status;
    this->Servicestatus_ = ServiceStatus;
    this->rank_ = rank;
}

Soldier::Soldier(int ID, string name, string surname, string midname)
{
    this->ID_ = ID;
    this->name_ = name;
    this->surname_ = surname;
    this->midname_ = midname;
}

int Soldier::get_id()
{
    return this->ID_;
}

int Soldier::get_day()
{
    return this->day_;
}

int Soldier::get_mounth()
{
    return this->mounth_;
}

int Soldier::get_year()
{
    return this->year_;
}

string Soldier::get_name()
{
    return this->name_;
}

string Soldier::get_midname()
{
    return this->midname_;
}

string Soldier::get_surname()
{
    return this->surname_;
}

string Soldier::get_job()
{
    return this->job_;
}

string Soldier::get_education()
{
    return this->education_;
}

string Soldier::get_place_of_study()
{
    return this->place_of_study_;
}

void Soldier::set_id(int id)
{
    ID_ = id;
}

void Soldier::set_day(int day)
{
    this->day_ = day;
}

void Soldier::set_mounth(int mounth)
{
    this->mounth_ = mounth;
}

void Soldier::set_year(int year)
{
    this->year_ = year;
}

void Soldier::set_name(string name)
{
    name_ = name;
}

void Soldier::set_surname(string surname)
{
    surname_ = surname;
}

void Soldier::set_midname(string midname)
{
    midname_ = midname;
}

void Soldier::set_job(string job)
{
    job_ = job;
}

void Soldier::set_education(string education)
{
    education_ = education;
}

void Soldier::set_place_of_study(string place_of_study)
{
    place_of_study_ = place_of_study;
}

void Soldier::set_HealthGraph(int HG)
{
    HealthGraph_ = HG;
}

void Soldier::set_rank(string rank)
{
    rank_ = rank;
}

void Soldier::set_Status(bool status)
{
    Status_ = status;
}

void Soldier::set_ServiceStatus(bool ServiceStatus)
{
    Servicestatus_ = ServiceStatus;
}

string Soldier::get_rank()
{
    return this->rank_;
}

int Soldier::get_HealthGraph()
{
    return this->HealthGraph_;
}

bool Soldier::get_Status()
{
    return this->Status_;
}

bool Soldier::get_ServiceStatus()
{
    return this->Servicestatus_;
}


void Soldier::show()const
{
    cout << "Function SHOW" << endl;
}

void showSoldier(vector<Soldier> soldier)
{
    for (int i = 0; i < soldier.size(); i++)
    {
        cout << soldier[i] << endl;
    }
}

void addSoldier(vector<Soldier>& soldier)
{
    Soldier S;
    cout << "Enter the informations about soldier: " << endl;

    soldier.push_back(S);
}

bool operator ==(const Soldier &soldier1, const Soldier &soldier2)
{
    return ((!soldier1.name_.compare(soldier2.name_)) || (!soldier1.surname_.compare(soldier2.surname_))
        || ((!soldier1.midname_.compare(soldier2.midname_))));
}

ostream& operator<<(ostream &out, Soldier &soldier)
{
    out << soldier.get_name() << " " << soldier.get_midname() << " "
        << soldier.get_surname() << " " << soldier.get_education() << " " << soldier.get_job() << " "
        << soldier.get_HealthGraph() << " " << soldier.get_Status() << " " << soldier.get_rank() << " "
        << soldier.get_ServiceStatus();
    return out;
}

Soldier::~Soldier()
{ }
