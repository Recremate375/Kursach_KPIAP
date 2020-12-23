#include "Header.h"
using namespace std;

class Human
{
protected: 
    int ID;
    string name, surname, midname;
    string job, education;
    virtual void add() = 0;
    virtual void show() = 0;
};

class Soldier : public Human
{
private:
    bool Status;
    bool Sevstatus;
    string rank;
public:
    
    Soldier()
    {
        cout << "Vmsis ne oshibka" << endl;
    }
    
    Soldier(string name, string surname, string midname, string job, string education)
    {
        this->name = name;
        this->surname = surname;
        this->midname = midname;
        this->job = job;
        this->education = education;
    }
    
    int get_id();
    string get_name();
    string get_surname();
    string get_midname();

    void add();
    void show();

};